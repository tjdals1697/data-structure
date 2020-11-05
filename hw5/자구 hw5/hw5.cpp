#include <iostream>
using namespace std;

const int max_size = 7;

class Tree {
private:
	int max_size;
	int data;
	int *arr;
public:
	Tree(int size) {
		max_size = size;
		arr = new int[size];
		data = 0;
	}
	void insertTree(int value);
	void printTree();
	void makezero();
	int getTree();
};

void Tree::insertTree(int value) {
	arr[data] = value;
	data++;
}

void Tree::printTree() {
	for (int i = 0; i < max_size; i++)
		cout << arr[i] << " ";
}

void Tree::makezero() {
	data = 0;
}


int Tree::getTree() {
	int result;
	result = arr[data];
	data++;
	return result;
}

class Heap {
	int data[max_size];
	int n;
public:
	Heap();
	bool isEmpty();
	bool isFull();
	void insertHeap(int item);
	int deleteHeap();
	void printHeap();
	int Heaplevel();
};

Heap::Heap() :n(0) {
	for (int i = 0; i < max_size; i++)
		data[i] = 0;
}

bool Heap::isEmpty() {
	if (n == 0)
		return true;
	else
		return false;
}


bool Heap::isFull() {
	if (n == max_size)
		return true;
	else
		return false;
}


void Heap::insertHeap(int item) {
	int i;
	if (isFull()) {
		cout << "Heap is Full" << endl;
		return;
	}
	i = ++n;
	while ((i != 1) && (item < data[i / 2])) {
		data[i] = data[i / 2];
		i = i / 2;
	}
	data[i] = item;
}

int Heap::deleteHeap() {
	if (isEmpty()) {
		cout << "Heap is empty" << endl;
		return 0;
	}
	int parent, child, temp, item;

	item = data[1];
	temp = data[n--];
	parent = 1;
	child = 2;

	while (child <= n) {
		if ((child < n) && (data[child] > data[child + 1]))
			child++;
		else if (temp <= data[child])
			break;
		data[parent] = data[child];
		parent = child;
		child = child * 2;
	}
	data[parent] = temp;
	return item;
}

void Heap::printHeap() {
	if (!isEmpty())
		for (int i = 1; i <= n; i++)
			cout << data[i] << " ";
	else
		cout << "Heap is Empty!" << endl;
}

int Heap::Heaplevel() {
	return int(log2(n) + 1);
}

int main() {
	int size = 7;
	int i = 5;
	int input;

	Tree a(i);

	cout << "Enter data : ";

	for (int j = 0; j < i; j++) {
		cin >> input;
		a.insertTree(input);
	}

	cout << "Print Tree : ";
	a.printTree();
	cout << endl;
	a.makezero();

	int t = 1;
	int num;
	Heap h;

	for (int k = 0; k < i; k++)
		h.insertHeap(a.getTree());

	cout << "Basic Heap : ";
	h.printHeap();
	cout << endl;

	while (t) { //t = 1 이므로 무한반복문을 사용함
		int k;
		cout << "1.Insert  2.Delete  3.Empty  4.Full  5.Heaplevel  6.Quit" << endl;
		cin >> k;

		switch (k) {
		case 1: // insert heap
			cout << "Insert : ";
			cin >> num;
			h.insertHeap(num);
			cout << "Heap : ";
			h.printHeap();
			cout << endl;
			break;
		case 2: // Delete heap
			cout << "Delete" << endl;
			h.deleteHeap();
			cout << "Heap : ";
			h.printHeap();
			cout << endl;
			break;
		case 3: // Empty heap
			if (h.isEmpty())
				cout << "Heap is Empty" << endl;
			else
				cout << "Heap is not Empty" << endl;
			break;
		case 4: // Full heap
			if (h.isFull())
				cout << "Heap is Full" << endl;
			else
				cout << "Heap is not Full" << endl;
			break;
		case 5: // Heap level
			cout << h.Heaplevel() << endl;
			break;
		case 6: // exit
			cout << "프로그램 종료" << endl;
			t = 0;
			break;
		}
	}
}
