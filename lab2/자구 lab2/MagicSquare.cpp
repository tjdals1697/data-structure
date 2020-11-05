#include<iostream>
using namespace std;

void Magic(const int n);

int main(void)
{
	int Mnum;
	cout << "n*n행렬";
	cin >> Mnum;

	Magic(Mnum);
}

void Magic(const int n)
{
	const int MaxSize = 100;
	int square[MaxSize][MaxSize], k, l;

	if ((n > MaxSize) || (n < 1)) {
		cout << "초과.\n";
		exit(1);
	}
	else if (n % 2 == 0) {
		cout << "짝수 \n";
		exit(1);
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (x == 0 && y == (n - 1) / 2)
				square[x][y] = 1;
			else
				square[x][y] = 0;
		}
	}

	int key = 2, i = 0, j = (n - 1) / 2; 

	while (key <= n * n) {
		if (i - 1 < 0) 
			k = n - 1;
		else
			k = i - 1;
		if (j - 1 < 0) 
			l = n - 1;
		else
			l = j - 1;
		if (square[k][l]) 
			i = (i + 1) % n;
		else {
			i = k;
			j = l;
		}

		square[i][j] = key; key++;
	}

	cout << "magic square of size " << n << endl; 
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << square[x][y];
			if (square[x][y] / 10 == 0)
				cout << "  ";
			else
				cout << " ";
		}
		cout << endl;
	}
}