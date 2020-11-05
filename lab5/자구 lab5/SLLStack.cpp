#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node *next;
	Node(int value) {
		data = value;
		next = 0;
	}
	friend class linkedStack;
};

class linkedStack {
private:
	Node *head;

public:
	linkedStack() { head = 0; }
	~linkedStack() {};
	void createStack();
	void push(int);
	int pop();
	int isEmpty();
	void displayStack();
	void searchStack(int);
};

void linkedStack::createStack() {
	head = 0;
}

void linkedStack::push(int data) {
	Node *temp = new Node(data);

	if (head == 0)
		head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}

int linkedStack::pop() {
	Node *p;
	int num;

	num = head->data;
	p = head;
	head = head->next;
	delete p;
	return num;
}

int linkedStack::isEmpty() {
	if (head == 0)
		return 1;
	else
		return 0;
}

void linkedStack::displayStack() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Stack is empty" << endl;
}

void linkedStack::searchStack(int num) {
	Node *p;

	if (head != 0) {
		p = head;
		while (p != 0 && p->data != num) {
			p = p->next;
		}
		if (p) {
			cout << p->data << " is found." << endl;
		}
		else {
			cout << num << " is not in the list." << endl;
		}
	}
	else {
		cout << "List is empty\n";
	}
}

int main() {
	linkedStack a;

	a.push(10);
	a.push(30);
	a.push(20);
	a.pop();
	a.searchStack(20);
	a.push(50);
	a.displayStack();
	a.searchStack(10);
}