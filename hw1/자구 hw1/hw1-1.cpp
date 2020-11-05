/************************************************************
* Name : 양성민
* Student ID : 20163124
* Program ID : hw1-1
* Description : 희소행렬의 행과 열을 바꿔서 출력하는 목적
* Algorithm : Matrix A를 불러와서 구조체 배열 안에 저장하고
*			  행과 열을 바꿔서 출력함
* Variables : term - 구조체 생성
*			  fast_transpose - Matrix A와 Matrix B의 row, col 값을 바꿔 줌
*
*************************************************************/
#include <iostream>
#include <fstream>
#include <cstdio>
#define MAX_COL 10
#pragma warning(disable:4996) //4996번에 해당하는 warning 무시

using namespace std;
/**********************************************************
* function : term
* description : 행, 열, 데이터 값을 구조체에 저장함
* Variables : row - 행
			  col - 열
			  value - 데이터 값
***********************************************************/
struct term {
	int row;
	int col;
	int value;
};

term a[MAX_COL]; //구조체 배열 선언
term b[MAX_COL];

/**********************************************************
* function : fast_transpose
* description : Maxtrix A에서 Matrix B로 변환시켜 줌
* value : starting_pos - 데이터 안에서 각 행들이 시작하는 위치
*		  num_col - term a의 col값
*		  cum_terms - term a의 value 값
***********************************************************/

void fast_transpose(term a[], term b[]) {
	int row_transpose[MAX_COL]; 
	int starting_pos[MAX_COL];
	int num_col = a[0].col;
	int num_terms = a[0].value;

	b[0].row = a[0].col; //행을 열로
	b[0].col = a[0].row; //열을 행으로
	b[0].value = num_terms; //데이터 값 저장

	if (num_terms > 0) { //구조체 배열에 MatrixA 를 MatrixB로 변환하여 저장
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

	for (int i = 0; i < 9; i++) { //파일 입력받기
		fscanf(f, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
		cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	}

	cout << endl;
	cout << "Transpose A -> B" << endl;
	cout << endl;

	fast_transpose(a, b);

	for (int i = 0; i < 9; i++) //Maxtrix B 출력
		cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
}