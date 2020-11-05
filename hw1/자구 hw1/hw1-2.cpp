/*************************************************************
* Name : �缺��
* Student ID : 20163124
* Program ID : hw1-2
* Description : �� ������ ������ �ҷ��ͼ� ���̸� ���ϴ� ����
* Algorithm : �� ������ �̸��� �����Ͽ� ���̸� ���ϴ� ����� �ٸ��� �ϰ�
*			  ����ü �迭�� �̿��Ͽ� ������ ���̰� �ش��ϴ� area��
*			  ������ ��.
* Variables : shapes - ����ü ����
*			  shapesName - ������ �̸� ����
**************************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SHA 8 //�迭�� ũ�� ����

/*********************************************************
* function : shapes
* description : �������� ������ ����ü�� ������
* variables : char name : ������ �̸� ����
*			double len A : ���� 1�� ����
*			double len B : ���� 2�� ����
*			double radius : ���� �������� ����
*			double area : ������ ���̸� ����
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
* description : ������ �̸��� ������
* variables : *char name : ����ü �迭�� name�� ����Ŵ
**********************************************************/
int shapesName(char *name) {
	if (!strcmp(name, "rectangle")) return -1;
	else if (!strcmp(name, "circle")) return 1;
	else return 0;
}

int main() {
	ifstream fin;
	fin.open("hw1-2.txt", ios::in); //���� �Է��� ����� �� �ְ� ������

	shapes sha[MAX_SHA];

	cout << fixed;
	cout.precision(2); //cout�� �Ҽ��� 2��° �ڸ����� ����ϵ��� ��

	while (!fin.eof()) { 
		for (int i = 0; i < MAX_SHA; i++) {
			fin >> sha[i].name; //������ �Է� �޾Ƽ� name�� ����
			switch (shapesName(sha[i].name)) {
			case 1 : //circle�� �ش��ϴ� ����
				fin >> sha[i].radius;
				sha[i].area = sha[i].radius * sha[i].radius * 3.14;
				break;
			case 0 : //triangle�� �ش��ϴ� ����
				fin >> sha[i].lenA >> sha[i].lenB;
				sha[i].area = sha[i].lenA * sha[i].lenB / 2;
				break;
			case -1 : //rectangle�� �ش��ϴ� ����
				fin >> sha[i].lenA >> sha[i].lenB;
				sha[i].area = sha[i].lenA * sha[i].lenB;
				break;
			}
		}
	}
	fin.close(); //������ ������ �ݾ���

	for (int j = 0; j < MAX_SHA-1; j++) { //����ü �迭 MAX_SHA-1 ��ŭ �迭�� �����
		if (!strcmp(sha[j].name, "circle"))
			cout << sha[j].name << " " <<  sha[j].radius << " " << sha[j].area << endl; //circle�̸� ������ �ϳ� ����ϵ��� ��
		else
			cout << sha[j].name << " " << sha[j].lenA << " " << sha[j].lenB << " " << sha[j].area << endl; //rectangle, triangle�� ���� 2���� ����ϵ��� ��
	}
}