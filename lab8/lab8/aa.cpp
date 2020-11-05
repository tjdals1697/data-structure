#include<iostream>
#include<string>
using namespace std;

class Node {
private:
	int data;
	Node* right;
	Node* left;
	friend class Tree;
public:
	Node() {}
	~Node() {}
};
class Tree {
private:
	Node * root;
	int first = 0;
	int count = 0;
public:
	Tree() {
		root = NULL;
	}
	void insert_(int data);
	Node* insert_BST(Node* ptr, int data);
	void search_(int data); //search 함수
	Node* search_BST(Node* ptr, int data);
	void delete_(int data); //delete 함수
	Node* delete_BST(Node* ptr, int data);
	Node* find_min(Node* ptr);
	Node* find_max(Node* ptr);
	void drawTree();
	void drawTree_BST(Node* ptr, int level);
	void inorder(Node *ptr);
	void postorder(Node *ptr);
	void preorder(Node *ptr);
	int leaf(Node *ptr);
	Node* getRoot();
};
void Tree::drawTree()
{
	Node* ptr = root;
	if (ptr != NULL)
		drawTree_BST(ptr, 1);
	else
		cout << "Tree not Exist" << endl;
}
void Tree::drawTree_BST(Node* ptr, int level) 
{
	if (ptr != 0 && level <= 7) {
		drawTree_BST(ptr->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
			cout << "      ";	
		cout << ptr->data;					 
		if (ptr->left != 0 && ptr->right != 0) cout << " <" << endl;			//자식 노드가 왼쪽, 오른쪽 모두 있을 경우
		else if (ptr->right != 0) cout << " /" << endl;						//자식 노드가 오른쪽에만 있을 경우
		else if (ptr->left != 0) cout << " ＼" << endl;						//자식 노드가 왼쪽에만 있을 경우
		else cout << endl;
		drawTree_BST(ptr->left, level + 1);
	}
}
Node* Tree::find_min(Node* ptr) 
{
	if (ptr->left == NULL)
	{
		return ptr;	
	}
	else
		find_min(ptr->left);
}
Node* Tree::find_max(Node* ptr)
{
	if (ptr->right == NULL)
	{
		return ptr;	
	}
	else
		find_max(ptr->right);	
}
void Tree::delete_(int data)
{
	Node* ptr = root;
	delete_BST(ptr, data);
}
Node* Tree::delete_BST(Node* ptr, int data)
{
	if (ptr != NULL) {
		if (data == root->data)		
		{
			if ((ptr->left == NULL) && (ptr->right == NULL))
			{
				first = 0;
				Node* p = ptr;
				delete(p);	
				root = NULL;
			} 
			else if (ptr->right == NULL)	
			{
				Node* p = ptr;
				ptr = find_max(ptr->left);	
				root = ptr;			
				delete(p);
			}
			else if (ptr->left == NULL)
			{
				Node* p = ptr;
				ptr = find_max(ptr->right);	
				root = ptr;	
				delete(p);
			}
			else
			{
				int data2;
				Node* temp = find_min(ptr->right);
				data2 = temp->data;	
				ptr->right = delete_BST(ptr->right, data2);
				ptr->data = data2;		
				root = ptr;
			}
		}
		else
		{
			if (data < ptr->data)
				ptr->left = delete_BST(ptr->left, data);
			else if (data > ptr->data)
				ptr->right = delete_BST(ptr->right, data);
			else if ((ptr->left == NULL) && (ptr->right == NULL)) 
			{
				Node* p = ptr; ptr = NULL; delete(p);
			}
			else if (ptr->left == NULL) {	
				Node* p = ptr; ptr = ptr->right; delete(p);
			}
			else if (ptr->right == NULL) {
				Node* p = ptr; ptr = ptr->left; delete(p); 
			}
			else
			{
				Node* temp = find_max(ptr->right);
				ptr->data = temp->data;
				ptr->right = delete_BST(ptr->right, ptr->data);
			}
		}
	}
	else cout << "Tree is empty" << endl;
	return ptr;
}
void Tree::search_(int data) 
{
	Node* ptr = root;
	if (search_BST(ptr, data) != NULL)
		cout << data << " is in Tree" << endl;
	else
	cout << "Not Found" << endl;
}
Node* Tree::search_BST(Node* ptr, int data)	
{
	if (ptr == NULL)
		return ptr; 
	else {
		if (data == ptr->data)
			return ptr;
		else if (data < ptr->data)
			ptr = search_BST(ptr->left, data);
		else if (data > ptr->data)
			ptr = search_BST(ptr->right, data);
	}
	return ptr;	
}
void Tree::insert_(int data) 
{
	Node* ptr = root;
	insert_BST(ptr, data);	
}
Node* Tree::insert_BST(Node* ptr, int data)
{
	Node* temp = NULL;
	if (ptr == NULL && first == 0) {
		temp = new Node(); 
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
		first = 1;

		return temp;
	}
	else if (ptr == NULL)
	{
		temp = new Node();
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}
	else if (data < ptr->data)
		ptr->left = insert_BST(ptr->left, data);
	else if (data > ptr->data)
		ptr->right = insert_BST(ptr->right, data);
	return ptr;
}

void Tree::inorder(Node *ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << " ";
		inorder(ptr->right);
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

Node* Tree::getRoot() {
	return root;
}

int Tree::leaf(Node *ptr) {
	int cnt = 0;
	if (ptr == 0) {
		return cnt;
	}
	else {
		if ((ptr->left == NULL) && (ptr->right == NULL)) {
			cnt++;
		}
		else {
			cnt = leaf(ptr->left) + leaf(ptr->right);
		}
	return cnt;
	}
}

int main() {
	Tree bsttree;
	int num;
	string input;
	while (1) {
		cout << " 1. Insert, 2. Delete, 3. Search, 4. Print, 5. leaf, 6. Travese, 7. Quit " << endl;
		cin >> input;
		if (input == "1"){
			cout << "insert Num : ";
			cin >> num;
			bsttree.insert_(num);
			
		}
		else if (input == "2"){
			cout << "delete Num : ";
			cin >> num;
			bsttree.delete_(num);
			
		}
		else if (input == "3"){
			cout << "search Num : ";
			cin >> num;
			bsttree.search_(num);
		}
		else if (input == "4")
			bsttree.drawTree();
		else if (input == "5")
			bsttree.leaf(bsttree.getRoot());
		else if (input == "6") {
			if (bsttree.getRoot() == NULL)
				cout << "Tree is empty" << endl;
			bsttree.inorder(bsttree.getRoot());
			cout << endl;
			bsttree.preorder(bsttree.getRoot());
			cout << endl;
			bsttree.postorder(bsttree.getRoot());
			cout << endl;
		}
		else if (input == "7")
			exit(1);
	}
}