#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
	Node(int value) {
		data = value;
		next = 0;
		prev = 0;
	}
};

class Dll {
private:
	Node *head;
public:
	Dll() {
		head = 0;
	}
	~Dll();
	bool isEmpty();
	void insertList(int value);
	void deleteList(int value);
	void forwardList();
	void backwardList();
	void searchList(int value);
	void printNth(int value);
};

Dll::~Dll() {
	Node *p = head;

	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

bool Dll::isEmpty() {
	if (head == 0) return true;
	else return false;
}

void Dll::insertList(int value) {
	Node *temp = new Node(value);
	Node *p = 0;
	Node *q = 0;

	if (isEmpty()) {
		head = temp;
	}
	else if (temp->data < head->data) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		p = head;
		while (p != 0 && p->data < temp->data) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else {
			q->next = temp;
			temp->prev = q;
		}
	}
}

void Dll::deleteList(int value) {
	Node *p = 0;
	Node *q = 0;

	if (isEmpty())
		cout << "List is empty." << endl;
	else if (head->data == value) {
		if (head->next != 0) {
			p = head;
			head = head->next;
			head->prev = 0;
			delete p;
		}
		else
			head = 0;
	}
	else {
		p = head;
		while (p != 0 && p->data != value) {
			q = p;
			p = p->next;
		}
		if (p->next != 0 && p->data == value) {
			q->next = p->next;
			p->next->prev = q;
			delete p;
		}
		else if (p->next == 0 && p->data == value) {
			q->next = 0;
			delete p;
		}
		else
			cout << value << " is not in the list" << endl;
	}
}

void Dll::forwardList() {
	if (!isEmpty()) {
		Node *p = head;
		cout << "----- Forward List -----" << endl;
		while (p != 0) {
			cout << p->data << endl;
			p = p->next;
		}
	}
	else
		cout << "List is empty." << endl;
}

void Dll::backwardList() {
	if (!isEmpty()) {
		Node *p = head;
		while (p->next != 0)
			p = p->next;
		cout << "----- Backward List -----" << endl;
		while (p != 0) {
			cout << p->data << endl;
			p = p->prev;
		}
	}
	else
		cout << "List is empty." << endl;
}

void Dll::searchList(int value) {
	if (!isEmpty()) {
		Node *p = head;
		while (p != 0 && p->data != value)
			p = p->next;
		if (p != 0)
			cout << p->data << " is in the list" << endl;
		else
			cout << value << " is not in the list" << endl;
	}
	else
		cout << "List is empty." << endl;
}

void Dll::printNth(int value) {
	Node *p = head;
	int pos = 1;

	if (isEmpty())
		cout << "List is empty." << endl;
	else {
		while (p != 0) {
			if (pos == value) {
				cout << "data of " << value << " list : " << p->data << endl;
				break;
			}
			p = p->next;
			pos++;
		}
		if (p == 0) {
			cout << value << " list is not in the list." << endl;
		}

	}
}

int main() {
	Dll ll;

	ll.insertList(20);
	ll.insertList(10);
	ll.insertList(15);

	ll.forwardList();
	ll.backwardList();

	ll.~Dll();
}