#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

static const char prec[4][2] = { '*', 2,  '/', 2,  '+', 1,  '-', 1 };

class Node
{
private:
	char data;
	int prio;
	Node *left;
	Node *right;

public:
	Node(char value);
	friend class Tree;
};

class Tree
{
private:
	Node *root;
public:
	Tree();
	//~Tree();

	void inorder(Node *ptr);
	void postorder(Node *ptr);
	void preorder(Node *ptr);
	void insertInorder();
	void insertPostorder();
	void insertPreorder();

	//void insertTree();
	void buildtree(char input);
	void treeOperand(Node *new_node);
	void treeOperator(Node *new_node);
	int evalTree(Node *p);
	void insertEval();
	// void Tree::drawTree();
	// void Tree::drawBSTree(Node *p, int level);
};

Node::Node(char value)
{
	data = value;
	prio = 5;
	left = 0;
	right = 0;
}

Tree::Tree()
{
	root = 0;
}

void Tree::insertInorder()
{
	inorder(root);
}
void Tree::insertPostorder()
{
	postorder(root);
}
void Tree::insertPreorder()
{
	preorder(root);
}

void Tree::inorder(Node *ptr)
{
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data;
		inorder(ptr->right);
	}
}

void Tree::postorder(Node *ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data;
	}
}

void Tree::preorder(Node *ptr)
{
	if (ptr)
	{
		cout << ptr->data;
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void Tree::buildtree(char input)
{
	int i;

	while (input != NULL)
	{
		Node *temp = new Node(input);

		for (i = 0; i < 4; i++) {
			if (temp->data == prec[i][0]) {
				temp->prio = (prec[i][1]);
			}
		}

		if (temp->prio == 5) {
			treeOperand(temp);
			break;
		}
		else {
			treeOperator(temp);
			break;
		}
	}
}

void Tree::treeOperand(Node *new_node)
{
	Node *p;
	if (root == NULL) {
		root = new_node;
		return;
	}
	p = root;
	while (p->right != NULL)
		p = p->right;
	p->right = new_node;
}

void Tree::treeOperator(Node *new_node)
{
	if (root->prio >= new_node->prio) {
		new_node->left = root;
		root = new_node;
	}
	else {
		new_node->left = root->right;
		root->right = new_node;
	}
}

void Tree::insertEval()
{
	cout << evalTree(root);
}

int Tree::evalTree(Node *p)
{
	int value;
	int left;
	int right;

	if (p != NULL) {
		if (p->left == 0 && p->right == 0)
			value = p->data - '0';
		else {
			left = evalTree(p->left);
			right = evalTree(p->right);
			switch (p->data) {
			case '+': value = left + right; break;
			case '-': value = left - right; break;
			case '*': value = left * right; break;
			case '/': value = left / right; break;
			case '^': value = pow(left, right); break;
			}
		}
	}
	else {
		cout << "Empty Tree";
		return 0;
	}
	return value;
}
/*
void Tree::drawTree()
{
	drawBSTree(root, 1);
}
void Tree::drawBSTree(Node *p, int level)
{
	if (p != 0 && level <= 7) {
		drawBSTree(p->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
			cout << "   ";
		cout << setw(4) << p->data;
		if (p->left != 0 && p->right != 0)
			cout << "<" << endl;
		else if (p->right != 0)
			cout << "／" << endl;
		else if (p->left != 0)
			cout << "＼" << endl;
		else
			cout << endl;
		drawBSTree(p->left, level + 1);
	}
} */

int main()
{
	Tree tree;
	int i = 0;
	char sum[100];


	while (1)
	{
		int n;
		cout << "1.Insert  2.Inorder  3.Postorder  4.Preorder  5.Evaluation 6.Exit " << endl;
		cin >> n;

		switch (n)
		{
		case 1: // insert
			cout << "Insert => ";
			cin >> sum;
			i = 0;
			while (sum[i] != 0) {
				tree.buildtree(sum[i]);
				i++;
			}
			cout << endl;
			continue;
		case 2: // Inorder
			cout << "Inorder : ";
			tree.insertInorder();
			cout << endl << endl;
			continue;
		case 3: // Postorder
			cout << "Postorder : ";
			tree.insertPostorder();
			cout << endl << endl;
			continue;
		case 4: // Preorder
			cout << "Preorder : ";
			tree.insertPreorder();
			cout << endl << endl;
			continue;
		case 5: // Evaluation
			cout << "Evaluation : ";
			tree.insertEval();
			cout << endl << endl;
			continue;
		case 7: // exit
			cout << "프로그램을 종료합니다." << endl;
			break;

		}
		break;
	}
}
