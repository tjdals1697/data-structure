#include <iostream>

using namespace std;



class Heap {
private:
	int max_size;
	int index;
	int *heap;
public:
	Heap(int size) {
		max_size = size;
		heap = new int[max_size];
		index = 0;
	}
	bool isFull();
	bool isEmpty();
	void insertHeap(int element);
	int deleteHeap();
	int levelHeap();
	void printHeap();
};

bool Heap::isFull() {
	if (index == max_size)
		return true;
	else
		return false;
}

bool Heap::isEmpty() {
	if (index == 0)
		return true;
	else
		return false;
}

void Heap::insertHeap(int element) {
	int i;
	if (isFull()) {
		cout << "Heap is Full" << endl;
		return;
	}
	i = ++index;
	while ((i != 1) && (element < heap[i / 2])) {
		heap[i] = heap[i / 2];
		i = i / 2;
	}
	heap[i] = element;
}

int Heap::deleteHeap() {
	if (isEmpty()) {
		cout << "Heap is empty" << endl;
		return 0;
	}

	int parent, child, temp, item;

	item = heap[1];
	temp = heap[index--];
	parent = 1;
	child = 2;


	while (child <= index) {
		if ((child < index) && (heap[child] > heap[child + 1]))
			child++;
		else if (temp <= heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child = child * 2;
	}
	heap[parent] = temp;
	return item;
}

int Heap::levelHeap() {
	return int(log2(index) + 1);
}

void Heap::printHeap() {
	cout << " ( ";
	for (int i = 1; i < index + 1; i++) {
		cout << heap[i] << " ";
	}
	cout << ") " << endl;
}

int main() {
	int size = 7;
	int dataInput = 5;
	int input;

	Heap h1(size);
	

	h1.insertHeap(9);
	h1.insertHeap(2);
	h1.insertHeap(5);
	h1.insertHeap(3);
	h1.insertHeap(8);

	cout << "Min Heap : ";
	h1.printHeap();

	cout << "1. insert  2. delete  3. empty  4. full  5. level  6. exit" << endl;

	while (1) {
		cin >> input;
		switch (input) {
		case 1:
			int data;
			cin >> data;
			h1.insertHeap(data);
			cout << "Insert " << data << "\t\t : ";
			h1.printHeap();
			break;
		case 2:
			h1.deleteHeap();
			cout << "Delete\t\t\t : ";
			h1.printHeap();
			break;
		case 3:
			cout << "Empty test\t\t : ";
			if (h1.isEmpty())
				cout << "Heap is Empty" << endl;
			else
				cout << "Heap is not Empty" << endl;
			break;
		case 4:
			cout << "Full test\t\t : ";
			if (h1.isFull())
				cout << "Heap is Full" << endl;
			else
				cout << "Heap is not Full" << endl;
			break;
		case 5:
			cout << "Level test\t\t : ";
			cout << h1.levelHeap() << endl;
			break;
		case 6:
			cout << "Exit Program";
			return 0;
			break;
		}
	}
}