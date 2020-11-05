/************************************************************
* Name : �缺��
* Student ID : 20163124
* Program ID : hw1-1
* Description : �������� ��� ���� �ٲ㼭 ����ϴ� ����
* Algorithm : Matrix A�� �ҷ��ͼ� ����ü �迭 �ȿ� �����ϰ�
*			  ��� ���� �ٲ㼭 �����
* Variables : term - ����ü ����
*			  fast_transpose - Matrix A�� Matrix B�� row, col ���� �ٲ� ��
*
*************************************************************/
#include <iostream>
#include <fstream>
#include <cstdio>
#define MAX_COL 10
#pragma warning(disable:4996) //4996���� �ش��ϴ� warning ����

using namespace std;
/**********************************************************
* function : term
* description : ��, ��, ������ ���� ����ü�� ������
* Variables : row - ��
			  col - ��
			  value - ������ ��
***********************************************************/
struct term {
	int row;
	int col;
	int value;
};

term a[MAX_COL]; //����ü �迭 ����
term b[MAX_COL];

/**********************************************************
* function : fast_transpose
* description : Maxtrix A���� Matrix B�� ��ȯ���� ��
* value : starting_pos - ������ �ȿ��� �� ����� �����ϴ� ��ġ
*		  num_col - term a�� col��
*		  cum_terms - term a�� value ��
***********************************************************/

void fast_transpose(term a[], term b[]) {
	int row_transpose[MAX_COL]; 
	int starting_pos[MAX_COL];
	int num_col = a[0].col;
	int num_terms = a[0].value;

	b[0].row = a[0].col; //���� ����
	b[0].col = a[0].row; //���� ������
	b[0].value = num_terms; //������ �� ����

	if (num_terms > 0) { //����ü �迭�� MatrixA �� MatrixB�� ��ȯ�Ͽ� ����
		for (int i = 0; i < num_col; i++)
			row_transpose[i] = 0;
		for (int j = 1; j <= num_terms; j++)
			row_transpose[a[j].col]++;
			starting_pos[0] = 1;
		for (int i = 1; i < num_col; i++)
			starting_pos[i] = starting_pos[i - 1] + row_transpose[i - 1];
		for (int i = 1; i <= num_terms; i++) {
			int c = starting_pos[a[i].col]++;
			b[c].row = a[i].col;
			b[c].col = a[i].row;
			b[c].value = a[i].value;
		}
	}
}

int main() {
	FILE *f;

	f = fopen("hw1-1.txt", "r");

	for (int i = 0; i < 9; i++) { //���� �Է¹ޱ�
		fscanf(f, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
		cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	}

	cout << endl;
	cout << "Transpose A -> B" << endl;
	cout << endl;

	fast_transpose(a, b);

	for (int i = 0; i < 9; i++) //Maxtrix B ���
		cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
}