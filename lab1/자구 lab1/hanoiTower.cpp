#include<iostream>
#include<fstream>
using namespace std;

void hanoi(char from, char to, char aux, int n);

int main(void) {
	int disk;
	char A = 'A', B = 'B', C = 'C';

	cout << "Disk의 갯수를 쓰시오.  ";
	cin >> disk;
	hanoi(A, B, C, disk);

	return 0;
}

void hanoi(char from, char to, char aux, int n) {
	if (n == 1)
		cout << "move disk 1 from peg " << from << " to peg " << to << endl;
	else {
		hanoi(from, aux, to, n - 1);
		cout << "move disk " << n << " from peg " << from << " to peg " << to << endl;
		hanoi(aux, to, from, n - 1);
	}
}