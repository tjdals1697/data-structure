#include <iostream>
using namespace std;

const int stacksize = 5;

class Stack {
private:
	int Stack[stacksize];
	int top = -1;
public:
	bool SFull();
	bool SEmpty();
	void push(int num);
	void pop();
	void display();
};

bool Stack::SFull() {
	if (top == stacksize - 1)
		return true;
	else
		return false;
}

bool Stack::SEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

void Stack::push(int num) {
	if (SFull())
		cout << "Stack is Full" << endl;
	else
		Stack[++top] = num;
}

void Stack::pop() {
	if (SEmpty())
		cout << "Stack is Empty" << endl;
	else
		Stack[top--];
}

void Stack::display() {
	if (SEmpty())
		cout << "Stack is Empty" << endl;
	else {
		int i = top;
		while (i >= 0) {
			cout << Stack[i] << " ";
			i--;
		}
		cout << endl;
	}
}

int main() {
	Stack a;
	a.push(3); a.push(5); a.push(2); a.display();
	a.pop(); a.display();
}