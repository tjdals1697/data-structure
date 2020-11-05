#include <iostream>
using namespace std;

const int queuesize = 3;

class Queue {
private:
	int queue[queuesize];
	int front = -1;
	int rear = -1;
public:
	bool QFull();
	bool QEmpty();
	void Enque(int num);
	void Deque();
	void display();
};

bool Queue::QFull() {
	if (rear == queuesize - 1)
		return true;
	else
		return false;
}

bool Queue::QEmpty() {
	if (rear == -1)
		return true;
	else
		return false;
}

void Queue::Enque(int num) {
	if (QFull())
		cout << "Queue if Full" << endl;
	else
		queue[++rear] = num;
}

void Queue::Deque() {
	if (QEmpty())
		cout << "Queue if Empty" << endl;
	else
		queue[++front];
}

void Queue::display() {
	if (QEmpty())
		cout << "Queue is Empty" << endl;
	else {
		int i = front + 1;
		while (i <= rear) {
			cout << queue[i] << " ";
			i++;
		}
		cout << endl;
	}
}

int main() {
	Queue a;
	a.Enque(3); a.Enque(5); a.Enque(2); a.display();
	a.Deque(); a.display();
}