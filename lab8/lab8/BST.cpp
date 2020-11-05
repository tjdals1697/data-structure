#include <iostream>

using namespace std;

struct Node {
	int data;
	int prio;
	Node *left;
	Node *right;
	Node(int value) {
		data = value;
		left = 0;
		right = 0;
	}
};

class Tree {
private:
	Node *root = 0;
public:
	Tree() {
		root = 0;
	}
	Node *Insert(Node *ptr, int key);
	Node *search(Node *ptr, int key);
	Node *deletes(Node *ptr, int key);
	Node *find_min(Node *ptr);
	Node *find_max(Node *ptr);
	void drawBSTree(Node *ptr, int level);
	void inorder(Node *ptr);
	void postorder(Node *ptr);
	void preorder(Node *ptr);
	void leaf(Node *ptr);
};

Node *Tree::Insert(Node *ptr, int key) {
	Node *p;
	if (root == NULL) {
		Node *ptr = new Node(key);
		ptr->data = key;
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		p = root;
	}
	
	else if (key < ptr->data) {
		ptr->left = Insert(ptr->left, key);
	}
	else if (key > ptr->data) {
		ptr->right = Insert(ptr->right, key);
	}
	return ptr;
}

Node *Tree::search(Node *ptr, int key) {
	if (ptr == NULL)
		return NULL;
	else {
		if (key == ptr->data) {
			return ptr;
		}
		else if (key < ptr->data) {
			ptr = search(ptr->left, key);
		}
		else if (key > ptr->data) {
			ptr = search(ptr->right, key);
		}
	}
	return ptr;
}

Node *Tree::deletes(Node *ptr, int key) {
	if (ptr != NULL) {
		if (key < ptr->data) {
			ptr->left = deletes(ptr->left, key);
		}
		else if (key > ptr->data) {
			ptr->right = deletes(ptr->right, key);
		}
		else if ((ptr->left == NULL) && (ptr->right == NULL)) {
			ptr = NULL;
		}
		else if (ptr->left == NULL) {
			Node *p = new Node(0);
			p = ptr;
			ptr = ptr->right;
			delete(p);
		}
		else if (ptr->right == NULL) {
			Node *p = new Node(0);
			ptr = ptr->left;
			delete(p);
		}
		else {
			Node *temp = new Node(0);
			temp = find_max(ptr->right);
			ptr->data = temp->data;
			ptr->right = deletes(ptr->right, ptr->data);
		}
	}
	else
		cout << "Not found" << endl;
	return ptr;
}

Node *Tree::find_min(Node *ptr) {
	if (ptr->left == NULL) return ptr;
	else find_min(ptr->left);
}

Node *Tree::find_max(Node *ptr) {
	if (ptr->right == NULL) return ptr;
	else find_max(ptr->right);
}

void Tree::drawBSTree(Node *ptr, int level) {
	if (ptr != 0 && level <= 7) {
		drawBSTree(ptr->right, level + 1);
		cout << endl;
		for (int i = 1; i <= (level - 1); i++)
			cout << "    ";
		if (ptr->data != 0)
			cout << ptr->data;
		if (ptr->left != 0 && ptr->right != 0)
			cout << " < ";
		else if (ptr->right != 0)
			cout << " / ";
		else if (ptr->left != 0)
			cout << " ¡¬ ";
		drawBSTree(ptr->left, level + 1);
	}
}

void Tree::inorder(Node *ptr) {
	{
		if (ptr) {
			inorder(ptr->left);
			cout << ptr->data << " ";
			inorder(ptr->right);
		}
	}
}

void Tree::postorder(Node *ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << " ";

	}
}

void Tree::preorder(Node *ptr) {
	if (ptr) {
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void Tree::leaf(Node ptr) {
	if ()
}

int main() {
	Node *ptr = new Node(0);
	Tree a;
	a.deletes(ptr, 10);
	cout << endl;

	cout << endl;

	cout << endl;
	a.Insert(ptr, 30);
	a.Insert(ptr, 40);
	a.Insert(ptr, 20);
	a.Insert(ptr, 10);
	a.Insert(ptr, 50);

	cout << endl;
	a.drawBSTree(ptr, 1);
	cout << endl;

	cout << endl;
	

	cout << a.search(ptr, 70)->data << endl;
}