/*******************************************************************************************
* Name : �缺��
* Student ID : 20163124
* Program ID : hw4
* Description : Ű����� ���� �Է¹޾Ƽ� Inorder, Postorder, Preorder�� ���� ��ȯ�ϰ�
*			    �Ŀ� ���� ������� Tree�� �ش��ϴ� Parenthe��ses�� Tree Structure��
*				����ϴ� ���α׷�
* Algorithm : 1. Node�� data�� �켱������ prio�� �����ϰ� left�� right�� Node���·� ������.
*			  2. char������ ���� �Է¹����� buildtree���� ���ο� Node�� ����� �Է¹���
			     ���� *, /�̸� prio = 2, +, -�̸� prio = 1�� �ʱ�ȭ�ؼ� �켱������ ����.
			  3. if (temp->prio == 5) ������ �����Ѵٸ� �����̹Ƿ� Operand�� ����,
			     else ��� ��ȣ�̹Ƿ� Operator�� ��.
			  4. Operand�� isEmpty�϶� root = ptr; else��� p = root; p�� NULL�� �ɶ�����
				 p = p->right; �ϰ� p->right == NULL�̸� p->right = ptr;�� ������.
				 Operator�� root->prio >= ptr->prio��� ptr->left = root; root = ptr;
				 else { ptr->left = root->right; root->right = ptr;}
			  5. Inorder : inorder(ptr->left); cout << ptr->data << " "; inorder(ptr->right);
				 Postorder : postorder(ptr->left); postorder(ptr->right); cout << ptr->data << " ";
				 Preorder : cout << ptr->data << " "; preorder(ptr->left); preorder(ptr->right);
			  6. evalTree : if (!isEmpty)�̰� if (ptr->left == 0 && ptr->right == 0) �̸�
			     value = ptr->data - '0'; else �̸� left = evalTree(ptr->left);
				 right = evalTree(ptr->right);�� �ʱ�ȭ�ϰ� switch (ptr->data)�� ����Ͽ�
				 ���� 4���� case�� "*", "/", "+", "-" �̸� ���� case�� �´� ������ �����ϰ� 
				 return vlaue�� �����.
			  7. parentheses : if (ptr != NULL)�̰� if (ptr->prio != 5)�̸� "("�� ����� ��,
				 parentheses(ptr->left); cout << ptr->data << " "; parentheses(ptr->right);
				 �� '(' ��ȣ �ȿ� ���� ���� ����ϰ� if (ptr->prio != 5) �̸� ")"�������
				 ��ȣ�� �ݾ���.
			  8. DrawTree : if (Node *p != 0) �̸� recursive�� ����� DrawTree([->right, level+1);
				 �� �ٽ� DrawTree�� ���� level�� - 2 ��ŭ ���⸦ �Ѵ�.
				 ���� p == NULL�� �ɶ����� if (p->left != 0 && p->right != 0) print "<"
				 else if (p->right != 0) {cout << "/";}
				 else if (p->left != 0) {cout << "��";}�� �����ϰ�
				 �ٽ� recursive�� DrawTree(p->left, level+1);�� ���� p == NULL�� �ɶ�����
				 �ݺ��Ѵ�.
********************************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

const char const prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node {
	char data;
	int prio; //�켱����
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
	bool isdigit(int value); //�켱������ �������� True, False Ȯ��
	void inorder(Node *ptr); //��������
	void postorder(Node *ptr); //��������
	void preorder(Node *ptr); //��������
	void Operand(Node *ptr); //���ڸ� Tree�� ����
	void Operator(Node *ptr); //��ȣ�� Tree�� ����
	void buildTree(char input); //insert
	int evalTree(Node *ptr); //������ ��� ��
	void parentheses(Node *ptr); //Tree ������ �������� ��ȣ�� ���� ����
	Node* getRoot(); //root���� ������
	void DrawTree(Node *p, int level); //Tree ��ü ���
};

/***********************************************************************************
* function : isdigit
* description : �켱������ �Է¹ް� �켱������ 5�̸� True, �ƴ϶�� False
* Variables : value - data�� prio�� �޾ƿ�
************************************************************************************/
bool Tree::isdigit(int value) {
	if (value == 5)
		return true;
	else
		return false;
}

/***********************************************************************************
* function : isEmpty
* description : Tree�� ����ִ��� �ƴ��� Ȯ����
************************************************************************************/
bool Tree::isEmpty() {
	if (root == 0) 	return true;
	else	return false;
}

/***********************************************************************************
* function : inorder
* description : build�� Tree�� �ִ� ������ ������������ �����
* Variables : *ptr - Tree�� ���� �����ų Node
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
* description : build�� Tree�� �ִ� ������ ������������ �����
* Variables : *ptr - Tree�� ���� �����ų Node
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
* description : build�� Tree�� �ִ� ������ ������������ �����
* Variables : *ptr - Tree�� ���� �����ų Node
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
* description : �������� �̷���� data�� �Է¹����� new Node�� ����ϰ� ��ȣ�� left��
*				���ڴ� right�� ������
* Variables : input - Ű����� �ԷµǴ� ����
			  temp - Tree�� ���� �����ų Node
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
* description : ptr�� right�� ���ڸ� ������
* Variables : *ptr - Tree�� ���� �����ų Node
************************************************************************************/
void Tree::Operand(Node *ptr) { //����
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
* description : ptr�� left�� ��ȣ�� ������
* Variables : *ptr - Tree�� ���� �����ų Node
************************************************************************************/
void Tree::Operator(Node *ptr) { //��ȣ
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
* description : Tree�� ����� ������ �����Ͽ� ����� ���� �����
* Variables : *ptr - Tree�� ���� �����ų Node
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
* description : Tree�� ����� ������ �켱������ �������� ��ȣ �ȿ� �־ �����ϴ�
				������ ����
* Variables : *ptr - Tree�� ���� �����ų Node
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
* description : ��ü���� Tree�� �����
* Variables : *p - Tree�� ���� �����ų Node
			 level - root�ۿ� ���ٸ� level=1�̰� root�� child�� �ִٸ� level=2,
			child�� child�� �ִٸ� level=3���� Tree�� ���̸� �˷��ִ� ��
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
* description : root���� ������
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