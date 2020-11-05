#include<iostream>
#include <string>
using namespace std;

#define MAX 3

int CQ[MAX];
int stacktop = -1;
int queuetop = -1;
int resulttop = -1;
int queuedown = -1;
int stacksize = 2;
int queuesize = 3;
int resultsize = 4;
char stack[2];
char queue[3];
char result[5];
int front = 0;
int rear = 0;
bool CQisFull();
bool CQisEmpty();

//stack 함수
void push(char word) {
	stack[++stacktop] = word;
}

char pop() {
	return (stack[--stacktop]);
}

bool stackisEmpty() {
	return (stacktop == -1);
}

bool stackisFull() {
	return (stacktop == 1);
}

//queue 함수
void enque(char word) {
	queue[++queuetop] = word;
}

char deque() {
	return (queue[++queuedown]);
}

bool queueisEmpty() {
	return (queuedown == 2);
}

bool queueisFull() {
	return (queuetop == 2);
}

void resultappend(char word) {
	result[++resulttop] = word;
}

bool CQisEmpty() {
	if (front == rear)
		return true;
	else
		return false;
}

bool CQisFull() {
	if ((rear + 1) % MAX == front)
		return true;
	else
		return false;
}

void CenQue(char item) {
	if (CQisFull()) {
		cout << "Queue Full" << endl;
		exit(1);
	}
	else {
		rear = (rear + 1) % MAX;
		CQ[rear] = item;
	}
}

int CdeQue() {
	if (CQisEmpty()) {
		cout << "Queue Empty" << endl;
		exit(1);
	}
	else {
		front = (front + 1) % MAX;
		return CQ[front];
	}
}

string input;
char word;

int main() {
	while (true) {
		cout << "Enter : ";
		cin >> input;
		if (input == "push") {
			if (stackisFull() == false) {
				cout << "word = ";
				cin >> word;
				push(word);
			}
			else {
				cout << "Stack is Full" << endl;
			}
		}
		else if (input == "pop") {
			if (stackisEmpty() == false) {
				if (resulttop != 4) {
					resultappend(stack[stacktop]);
				}
				if (resulttop == 4) {
					for (int i = 0; i < resulttop + 1; ++i) {
						cout << result[i];
					}
					cout << endl;
				}
				pop();
			}
			else {
				cout << "Stack is Empty" << endl;
			}
		}
		else if (input == "enque") {
			if (queueisFull() == false) {
				cout << "word = ";
				cin >> word;
				enque(word);
			}
			else {
				cout << "Queue is Full" << endl;
			}
		}
		else if (input == "deque") {
			if (queueisEmpty() == false) {
				deque();
				if (resulttop != 4) {
					resultappend(queue[queuedown]);
				}
				if (resulttop == 4) {
					for (int i = 0; i < resulttop + 1; ++i) {
						cout << result[i];
					}
					cout << endl;
				}
			}
			else {
				cout << "Queue is Empty" << endl;
			}
		}
		else if (input == "displaystack") {
			for (int i = 0; i < stacktop + 1; ++i) {
				cout << stack[i];
			}
			cout << endl;
		}
		else if (input == "displayqueue") {
			for (int i = queuedown + 1; i < queuetop + 1; ++i) {
				cout << queue[i];
			}
			cout << endl;
		}
		else if (input == "quit") {
			break;
		}
		/////////////////////////////////////////////////////
		int count;
		if (input == "c-enque") {
			if (!CQisFull()) {
				cout << "word : ";
				cin >> word;
				CenQue(word);
				count++;
			}
			else {
				cout << "Queue Full" << endl;
			}
		}
		else if (input == "c-deque") {
			if (!CQisEmpty()) {
				CdeQue();
				count--;
			}
			else {
				cout << "Queue Empty" << endl;
			}
		}
		else if (input == "DisplayCqueue") {
			for (int j = 1; j <= count; j++) {
				cout << CQ[(front + j) % MAX];
			}
			cout << endl;
		}
		else if (input == "quit") {
			break;
		}
	}
}