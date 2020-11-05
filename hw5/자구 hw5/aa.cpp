int t = 1;
int num;
Heap h;
h.insertHeap(9);
h.insertHeap(2);
h.insertHeap(5);
h.insertHeap(3);
h.insertHeap(8);

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