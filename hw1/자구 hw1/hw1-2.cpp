/*************************************************************
* Name : 양성민
* Student ID : 20163124
* Program ID : hw1-2
* Description : 각 도형의 제원을 불러와서 넓이를 구하는 목적
* Algorithm : 각 도형의 이름을 구별하여 넓이를 구하는 방법을 다르게 하고
*			  구조체 배열을 이용하여 각각의 넓이가 해당하는 area에
*			  들어가도록 함.
* Variables : shapes - 구조체 생성
*			  shapesName - 도형의 이름 구별
**************************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SHA 8 //배열의 크기 설정

/*********************************************************
* function : shapes
* description : 도형들의 제원을 구조체에 저장함
* variables : char name : 도형의 이름 저장
*			double len A : 길이 1을 저장
*			double len B : 길이 2를 저장
*			double radius : 원의 반지름을 저장
*			double area : 도형의 넓이를 저장
**********************************************************/
struct shapes {
	char name[10] = {};
	double lenA = 0;
	double lenB = 0;
	double radius = 0;
	double area = 0;
};
/*********************************************************
* function : shapesName
* description : 도형의 이름을 구별함
* variables : *char name : 구조체 배열의 name을 가리킴
**********************************************************/
int shapesName(char *name) {
	if (!strcmp(name, "rectangle")) return -1;
	else if (!strcmp(name, "circle")) return 1;
	else return 0;
}

int main() {
	ifstream fin;
	fin.open("hw1-2.txt", ios::in); //파일 입력을 사용할 수 있게 오픈함

	shapes sha[MAX_SHA];

	cout << fixed;
	cout.precision(2); //cout이 소숫점 2번째 자리까지 출력하도록 함

	while (!fin.eof()) { 
		for (int i = 0; i < MAX_SHA; i++) {
			fin >> sha[i].name; //파일을 입력 받아서 name에 저장
			switch (shapesName(sha[i].name)) {
			case 1 : //circle에 해당하는 연산
				fin >> sha[i].radius;
				sha[i].area = sha[i].radius * sha[i].radius * 3.14;
				break;
			case 0 : //triangle에 해당하는 연산
				fin >> sha[i].lenA >> sha[i].lenB;
				sha[i].area = sha[i].lenA * sha[i].lenB / 2;
				break;
			case -1 : //rectangle에 해당하는 연산
				fin >> sha[i].lenA >> sha[i].lenB;
				sha[i].area = sha[i].lenA * sha[i].lenB;
				break;
			}
		}
	}
	fin.close(); //오픈한 파일을 닫아줌

	for (int j = 0; j < MAX_SHA-1; j++) { //구조체 배열 MAX_SHA-1 만큼 배열을 출력함
		if (!strcmp(sha[j].name, "circle"))
			cout << sha[j].name << " " <<  sha[j].radius << " " << sha[j].area << endl; //circle이면 제원을 하나 출력하도록 함
		else
			cout << sha[j].name << " " << sha[j].lenA << " " << sha[j].lenB << " " << sha[j].area << endl; //rectangle, triangle은 제원 2개를 출력하도록 함
	}
}