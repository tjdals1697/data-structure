#include <iostream>

using namespace std;

int main(void)
{

	int square[3][3];
	int i, j;
	int n = 3;
	int row, col;

	for (i = 0; i < n; i++) //크기가 n인 행렬을 초기화
	{
		for (j = 0; j < n; j++)
		{
			square[i][j] = 0;
		}
	}
	square[0][(n - 1) / 2] = 1; //첫 행의 중간에 1삽입

	int key = 2; //1은 이미 첫 행의 중간에 삽입했으므로, 2부터 삽입
	i = 0, j = (n - 1) / 2; // 1이 채워진 현재 위치 row=0,col=(n-1)/2

	while (key <= n * n) //크기가 n인 행렬에 한 자리가 채워졌으므로 n-1만큼 루프실행
	{
		// 왼쪽 위로 이동
		if (i - 1 < 0) //i-1 ->한 칸 위로 이동
		{        //i가 0미만인 경우 -> 행렬의 범위를 벗어난 경우
			row = n - 1; //벗어난 경우 같은 열의 맨 마지막 행으로 이동
		}
		else
		{
			row = i - 1; //벗어나지 않은 경우 정상적으로 이동
		}
		if (j - 1 < 0) //j-1 -> 한 칸 왼쪽으로 이동
		{         //j가 0 미만 인 경우 -> 행렬의 범위를 벗어난 경우
			col = n - 1;  //벗어난 경우 같은 행의 맨 첫번째 열로 이동
		}
		else
		{
			col = j - 1; //벗어나지 않은경우 정상적으로 이동
		}
		if (square[row][col]) //이동한 곳에 이미 숫자가 채워져있다면
		{
			i = (i + 1) % n; //시작 지점의 한 칸 아래로 이동
		}
		else // 숫자가 채워져있지 않다면 그 위치를 시작점으로 잡음
		{
			i = row;
			j = col;
		}
		square[i][j] = key; //새로 시작점으로 잡은 곳에 숫자를 채워넣음.
		key++; // 다음 숫자
	}

	for (i = 0; i < n; i++) //크기가 n 인 행렬을 출력
	{
		for (j = 0; j < n; j++)
		{
			cout << square[i][j] << ' ';
		}
		cout << endl;
	}
}

