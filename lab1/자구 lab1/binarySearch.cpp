#include <iostream>
using namespace std;

int binarySearch(int data[], int num, int left, int right);

void main() {
	int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int num, found;

	cout << "Enter an integer to search : ";
	cin >> num;
	found = binarySearch(data, num, 0, 9);

	if (found == -1)
		cout << "Not in the list" << endl;
	else
		cout << "Found at position " << found + 1 << endl;
}

int binarySearch(int data[], int num, int left, int right) {
	int middle = (left + right - 1) / 2;

	if (right >= 1) {
		if (data[middle] == num)
			return middle;
		else if (data[middle] < num)
			return binarySearch(data, num, left, middle + 1);
		else
			return binarySearch(data, num, middle - 1, right);
	}
	else
		return -1;
}