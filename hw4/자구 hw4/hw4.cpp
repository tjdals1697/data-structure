/*******************************************************************************************
* Name : 양성민
* Student ID : 20163124
* Program ID : hw4
* Description : 키보드로 식을 입력받아서 Inorder, Postorder, Preorder로 식을 변환하고
*			    식에 대한 결과값과 Tree에 해당하는 Parenthe와ses와 Tree Structure를
*				출력하는 프로그램
* Algorithm : 1. Node에 data와 우선순위인 prio를 선언하고 left와 right를 Node형태로 선언함.
*			  2. char형으로 식을 입력받으면 buildtree에서 새로운 Node를 만들고 입력받은
			     값이 *, /이면 prio = 2, +, -이면 prio = 1로 초기화해서 우선순위를 정함.
			  3. if (temp->prio == 5) 조건을 충족한다면 숫자이므로 Operand로 들어가고,
			     else 라면 부호이므로 Operator로 들어감.
			  4. Operand는 isEmpty일때 root = ptr; else라면 p = root; p가 NULL이 될때까지
				 p = p->right; 하고 p->right == NULL이면 p->right = ptr;로 저장함.
				 Operator는 root->prio >= ptr->prio라면 ptr->left = root; root = ptr;
				 else { ptr->left = root->right; root->right = ptr;}
			  5. Inorder : inorder(ptr->left); cout << ptr->data << " "; inorder(ptr->right);
				 Postorder : postorder(ptr->left); postorder(ptr->right); cout << ptr->data << " ";
				 Preorder : cout << ptr->data << " "; preorder(ptr->left); preorder(ptr->right);
			  6. evalTree : if (!isEmpty)이고 if (ptr->left == 0 && ptr->right == 0) 이면
			     value = ptr->data - '0'; else 이면 left = evalTree(ptr->left);
				 right = evalTree(ptr->right);로 초기화하고 switch (ptr->data)를 사용하여
				 각각 4개의 case가 "*", "/", "+", "-" 이면 각각 case에 맞는 연산을 실행하고 
				 return vlaue로 출력함.
			  7. parentheses : if (ptr != NULL)이고 if (ptr->prio != 5)이면 "("를 출력한 후,
				 parentheses(ptr->left); cout << ptr->data << " "; parentheses(ptr->right);
				 로 '(' 괄호 안에 들어가는 값을 출력하고 if (ptr->prio != 5) 이면 ")"출력으로
				 괄호를 닫아줌.
			  8. DrawTree : if (Node *p != 0) 이면 recursive를 사용해 DrawTree([->right, level+1);
				 로 다시 DrawTree로 들어가고 level의 - 2 만큼 띄어쓰기를 한다.
				 이후 p == NULL이 될때까지 if (p->left != 0 && p->right != 0) print "<"
				 else if (p->right != 0) {cout << "/";}
				 else if (p->left != 0) {cout << "＼";}를 적용하고
				 다시 recursive로 DrawTree(p->left, level+1);로 들어가고 p == NULL이 될때까지
				 반복한다.
********************************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

const char const prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node {
	char data;
	int prio; //우선순위
	Node* left;
	Node* right;
	Node(char value) {
		data = value;
		prio = 4;
		left = 0;
		right = 0;
	}
};

class Tree {
private:
	Node *root;
public:
	Tree() {root = 0;}
	bool isEmpty();
	bool isdigit(int value); //우선순위를 기준으로 True, False 확인
	void inorder(Node *ptr); //중위연산
	void postorder(Node *ptr); //후위연산
	void preorder(Node *ptr); //전위연산
	void Operand(Node *ptr); //숫자를 Tree에 저장
	void Operator(Node *ptr); //부호를 Tree에 저장
	void buildTree(char input); //insert
	int evalTree(Node *ptr); //연산의 결과 값
	void parentheses(Node *ptr); //Tree 구성을 기준으로 괄호로 식을 만듦
	Node* getRoot(); //root값을 가져옴
	void DrawTree(Node *p, int level); //Tree 전체 출력
};

/***********************************************************************************
* function : isdigit
* description : 우선순위를 입력받고 우선순위가 5이면 True, 아니라면 False
* Variables : value - data의 prio를 받아옴
************************************************************************************/
bool Tree::isdigit(int value) {
	if (value == 5)
		return true;
	else
		return false;
}

/***********************************************************************************
* function : isEmpty
* description : Tree가 비어있는지 아닌지 확인함
************************************************************************************/
bool Tree::isEmpty() {
	if (root == 0) 	return true;
	else	return false;
}

/***********************************************************************************
* function : inorder
* description : build된 Tree에 있는 여산을 중위연산으로 출력함
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::inorder(Node *ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << " ";
		inorder(ptr->right);
	}
}

/***********************************************************************************
* function : postorder
* description : build된 Tree에 있는 여산을 후위연산으로 출력함
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::postorder(Node *ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << " ";

	}
}

/***********************************************************************************
* function : preorder
* description : build된 Tree에 있는 여산을 전위연산으로 출력함
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::preorder(Node *ptr) {
	if (ptr) {
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

/***********************************************************************************
* function : buildTree
* description : 연산으로 이루어진 data를 입력받으면 new Node를 사용하고 부호는 left에
*				숫자는 right에 저장함
* Variables : input - 키보드로 입력되는 연산
			  temp - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::buildTree(char input) {
	while (input != NULL) {
		Node *temp = new Node(input);

		for (int i = 0; i < 4; i++) {
			if (temp->data == prec[i][0]) {
				temp->prio = prec[i][1] - '0';
				break;
			}
			else {
				temp->prio = 5;
			}
		}

		if (temp->prio == 5) {
			Operand(temp);
			break;
		}
		else {
			Operator(temp);
			break;
		}
	}
}

/***********************************************************************************
* function : Operand
* description : ptr의 right에 숫자를 저장함
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::Operand(Node *ptr) { //숫자
	Node *p;
	if (isEmpty()) {
		root = ptr;
	}
	else {
		p = root;
		while (p->right != NULL) {
			p = p->right;
		}
		p->right = ptr;
	}
}

/***********************************************************************************
* function : Operator
* description : ptr의 left에 부호를 저장함
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::Operator(Node *ptr) { //부호
	if (root->prio >= ptr->prio) {
		ptr->left = root;
		root = ptr;
	}
	else {
		ptr->left = root->right;
		root->right = ptr;
	}
}

/***********************************************************************************
* function : evalTree
* description : Tree에 저장된 연산을 실행하여 계산한 값을 출력함
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
int Tree::evalTree(Node *ptr) {
	int value, left, right;
	if (!isEmpty()) {
		if (ptr->left == 0 && ptr->right == 0)
			value = ptr->data - '0';
		else {
			left = evalTree(ptr->left);
			right = evalTree(ptr->right);
			switch (ptr->data) {
			case '+':
				value = left + right;
				break;
			case '-':
				value = left - right;
				break;
			case '*':
				value = left * right;
				break;
			case '/':
				value = left / right;
				break;
			}
		}
	}
	else {
		cout << "Empty Tree" << endl;
		return 0;
	}

	return value;
}

/***********************************************************************************
* function : parentheses
* description : Tree에 저장된 연산을 우선순위를 기준으로 괄호 안에 넣어서 연산하는
				식으로 만듦
* Variables : *ptr - Tree에 값을 저장시킬 Node
************************************************************************************/
void Tree::parentheses(Node *ptr) {
	if (ptr != NULL) {
		if (!isdigit(ptr->prio))
			cout << "( ";
		parentheses(ptr->left);
		cout << ptr->data << " ";
		parentheses(ptr->right);
		if (!isdigit(ptr->prio))
			cout << ") ";
	}
}

/***********************************************************************************
* function : DrawTree
* description : 전체적인 Tree를 출력함
* Variables : *p - Tree에 값을 저장시킬 Node
			 level - root밖에 없다면 level=1이고 root의 child가 있다면 level=2,
			child의 child가 있다면 level=3으로 Tree의 깊이를 알려주는 값
************************************************************************************/
void Tree::DrawTree(Node *p, int level) {
	if (p != 0) {
		DrawTree(p->right, level + 1);
		cout << endl;
		for (int i = 1; i <= level - 1; i++)
			cout << "    ";
		cout << p->data;
		if (p->left != 0 && p->right != 0)
			cout << " < ";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "|";
		DrawTree(p->left, level + 1);
	}
}

/***********************************************************************************
* function : getRoot
* description : root값을 가져옴
************************************************************************************/
Node* Tree::getRoot() {
	return root;
}

int main() {
	Tree tree;
	char input[100];
	int i = 0;

	cout << "Enter expression : ";
	cin >> input;
	while (input[i] != 0) {
		tree.buildTree(input[i]);
		i++;
	}

	cout << endl;
	cout << "  InOrder : ";
	tree.inorder(tree.getRoot());
	cout << endl;

	cout << endl;
	cout << "  PostOrder : ";
	tree.postorder(tree.getRoot());
	cout << endl;

	cout << endl;
	cout << "  PreOrder : ";
	tree.preorder(tree.getRoot());
	cout << endl;

	cout << endl;
	cout << "  Evaluation : ";
	cout << tree.evalTree(tree.getRoot()) << endl;

	cout << endl;
	cout << "  Tree structure ";
	tree.DrawTree(tree.getRoot(), 1);
	cout << endl;
}