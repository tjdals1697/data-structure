#include <iostream>
using namespace std;

const int Queuesize = 3;
const int Stacksize = 2;

class Queue {
private:
	char queue[Queuesize];
	char Cqueue[Queuesize];
	int front = -1;
	int rear = -1;
public:
	void ENQUE(char item);
	void DEQUE();
	bool QFull();
	bool QEmpty();
	void display_Q();
	void CEnque(char item);
	void CDeque();
	void display_CQ();
};

class Stack {
private:
	char stack[Stacksize];

	int top = -1;
public:
	void push(char item);
	void pop();
	bool StackFull();
	bool StackEmpty();
	void display_stack();
};

void Queue::ENQUE(char item) {
	if (QFull()) {
		cout << "QueueFull,   " << endl;;
	}
	else {
		queue[++rear] = item;
	}
}

void Queue::DEQUE() {
	if (QEmpty()) {
		cout << "QueueEmpty" << endl;
	}
	else {
		cout << queue[++front] << " ";
	}
}

bool Queue::QFull() {
	if (rear == Queuesize - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Queue::QEmpty() {
	if (rear == front) {
		return true;
	}
	else {
		return false;
	}
}

void Queue::display_Q() {
	int i;
	if (QEmpty()) {
		cout << "QueueEmpty" << endl;
	}
	else {
		i = front + 1;
		cout << "Queue: ";
		while (i <= rear) {
			cout << queue[i] << " ";
			i = i + 1;
		}
		cout << endl;
	}
}

void Queue::CEnque(char item) {
	if (front == (rear + 1) % Queuesize) {
		cout << "QueueFull" << endl;
	}
	else {
		Cqueue[++rear] = item;
	}
}

void Queue::CDeque() {
	if (front == rear) {
		cout << "QueueEmpty";
	}
	else {
		front = (front + 1) % Queuesize;
	}
}

void Queue::display_CQ() {
	int i;
	if (front == rear) {
		cout << "QueueEmpty" << endl;
	}
	else {
		i = front + 1;
		while (i <= rear) {
			cout << Cqueue[i] << " ";
			i = i + 1;
		}
		cout << endl;
	}
}

void Stack::push(char item) {
	if (StackFull()) {
		cout << "StackFull,   ";
	}
	else {
		stack[++top] = item;
	}
}

void Stack::pop() {
	if (StackEmpty()) {
		cout << "StackEmpty   ";
	}
	else {
		cout << stack[top--] << " ";
	}
}

bool Stack::StackFull() {
	if (top == Stacksize - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Stack::StackEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void Stack::display_stack() {
	int i;
	if (StackEmpty()) {
		cout << "StackEmpty" << endl;
	}
	else {
		i = top;
		cout << "Stack: ";
			while (i >= 0) {
			cout << stack[i] << " ";
			i--;
		}
		cout << "  ";
	}
}

int main() {
	Queue q;
	Queue cq;
	Stack s;
	s.push('a'); q.ENQUE('b'); q.ENQUE('c'); q.ENQUE('d'); s.push('e'); //1번

	s.push('F'); q.ENQUE('G'); //2번

	s.display_stack(); q.display_Q(); //3번, 4번

	cout << "Output: ";
	s.pop(); q.DEQUE(); q.DEQUE(); q.DEQUE(); s.pop(); //5번
	cout << endl;

	s.pop(); q.DEQUE(); //6번

	cq.CEnque('A'); cq.CEnque('B'); cq.CEnque('C'); cq.CDeque(); cq.CEnque('D'); //7번

	cq.display_CQ(); //8번

	cq.CDeque(); cq.CDeque(); cq.CDeque(); //9번
}

