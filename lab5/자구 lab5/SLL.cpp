#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int value) {
		data = value;
		next = 0;
	}
};

class List {
private:
	Node *head = 0;
public:
	List() {
		head = 0;
	}
	bool isEmpty();
	void insertNode(int num);
	void deleteNode(int num);
	void traverseList();
	void searchList(int num);
	~List();
};

void List::insertNode(int data) {
	Node *temp = new Node(data);
	Node *p = head;
	Node *q = 0;

	if (head == 0) {
		head = temp;
	}
	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else {
			q->next = temp;
		}
	}
}


bool List::isEmpty() {
	if (head == 0) {
		return true;
	}
	else {
		return false;
	}
}

void List::deleteNode(int num) {
	Node *p = head;
	Node *q = 0;

	if (head->data == num) {
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while (p != 0 && p->data != num) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			q->next = p->next;
			delete p;
		}
		else {
			cout << num << "is not in the list\n";
		}
	}
}

void List::traverseList() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List is empty!\n";
	}
}

void List::searchList(int num) {
	Node *p;

	if (head != 0) {
		p = head;
		while (p != 0 && p->data != num) {
			p = p->next;
		}
		if (p) {
			cout << p->data << "is found." << endl;
		}
		else {
			cout << num << "is not in the list." << endl;
		}
	}
	else {
		cout << "List is empty\n";
	}
}

List::~List() {
	Node *p;

	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

int main() {
	List a;

	a.insertNode(10);
	a.insertNode(30);
	a.traverseList();
	a.insertNode(20);
	a.deleteNode(20);
	a.traverseList();
}