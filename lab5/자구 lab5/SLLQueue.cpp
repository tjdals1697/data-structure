#include <iostream>
using namespace std;

class Node {
private :
	int data;
	Node *next;
	Node(int value) { data = value; next = 0; }
	friend class linkedQueue;
};

class linkedQueue {
private :
	Node *front;
	Node *rear;

public:
	linkedQueue() { front = 0; rear = 0; }
	~linkedQueue() {};
	void createQueue();
	void enqueue(int);
	int dequeue();
	int isEmpty();
	void displayQueue();
	void searchQueue(int);
};

int linkedQueue::isEmpty() {
	if (front == 0)
		return 1;
	else
		return 0;
}

void linkedQueue::createQueue() {
	front = 0;
	rear = 0;
}

void linkedQueue::enqueue(int data) {
	Node *temp = new Node(data);

	if (front == 0) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}

int linkedQueue::dequeue() {
	Node *p;
	int num;

	num = front->data;
	p = front;

	if (front == rear) {
		front = 0;
		rear = 0;
	}
	else
		front = front->next;

	delete p;
	return num;
}

void linkedQueue::displayQueue() {
	Node *p;

	if (!isEmpty()) {
		p = front;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Queue is empty" << endl;
}

void linkedQueue::searchQueue(int num) {
	Node *p;

	if (front != 0) {
		p = front;
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
	linkedQueue a;

	a.enqueue(10);
	a.enqueue(30);
	a.enqueue(20);
	a.searchQueue(40);
	a.dequeue();
	a.displayQueue();
}