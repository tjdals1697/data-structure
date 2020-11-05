/************************************************************************************
* Name : �缺��
* Student ID : 20163124
* Program ID : hw3
* Description : data ������ ����ؼ� student�� name, ID, major, grade�� �Է� 
*				���� ��, ���� ���� �Լ��� ����ؼ� ���ǿ� �����ϴ� student��
*				data�� ����ϴ� ���α׷�
* Algorithm : 1. data���Ͽ� �ִ� student�� ������ ���� ����ü Node�� ������.
*			  2. class�� �������ְ� class �ȿ� node�� ���� ���� head�� �����ͺ���
*				�� �����ϰ� list�� ��������Ƿ� head�� 0���� ������
*			  3. data1�� ���� temp�� node�� �����ϰ� ������������ �����ϱ� ����
*				 p�� q�� �����Ͽ� name�� �������� ������������ �����Ѵ�.
*			  4. if (head == 0) { head = temp;}�� ����Ͽ� ����Ʈ�� ���������
*				 temp�� head�� ������
*			     head�� ũ�ٸ� head�� temp->next�� �ѱ�� temp�� head�� ������
*				 temp�� head���� ũ�ٸ� p�� q�� ����� �ϳ��� �Ѿ�� ���� ��
*				 �� ���ϸ� temp���� ū ���� ���� ������ �� ���� �ִ� q�� ������
*			  5. List�� ������ �ִ� ���� student�� data�� ��� ����ϱ� ���� p��
*				 head�� �ʱ�ȭ�Ͽ� next�� ���� �ϳ��� �Ѿ�� data���� ã�� �����
*			  6. ���ϴ� grade�� �ش��ϴ� student�� data�� ����ϱ� ���� p�� head��
*				 �ʱ�ȭ�ϰ� list�� ������� �ʴٸ� p�� null�� �� ������ p = p->next
*				 �ϰ� �Էµ� grade�� �ش�Ǵ� data�� ã�Ƽ� �����
*			  7. data1�� data2�� ������ ����Ʈ�� �ϳ��� ������� �ʴٸ� data1��
*				 ������ ����Ʈ�� head���� null���� List ll�� �����ϰ� data2�� ������
*				 ����Ʈ�� �̾ List ll�� �����Ͽ� data1�� data2�� ��ģ ����Ʈ��
*				 ������
*			  8. ���������� 2���� ��ģ List���� CS������ ����ϱ� ���� ����Ʈ��
*				 ������� ���� �� p�� head�� �����Ͽ� null�� �� ������ p = p->next
*				 �Ͽ� major�� CS�� �ش��ϴ� student data�� ã�Ƽ� �����
*				 (insert�� ������ ��� �Լ��� head == 0 �� �� "List Empty"�� �����)
*************************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
	char name;
	int ID;
	string major;
	char grade;
	Node *next;
	Node(char value, int num, string word, char abc) {
		name = value; //student�� �̸�
		ID = num; //student�� �й�
		major = word; //student�� ����
		grade = abc; //student�� ����
		next = 0;
	}
};

class List {
private:
	Node *head;
public:
	List() { head = 0; }
	//student�� ������ ������ List ����
	void insertList(char value, int num, string word, char abc);
	void searchGrade(char abc); //�Է��� ������ �ش�Ǵ� student�� ���
	void searchMajor(string word); //�Է��� ������ �ش�Ǵ� student�� ���
	void list(); //�Էµ� student�� ������ ��� ���
	List merge(List a, List b); //data1�� data2�� ���ļ� ����Ʈ�� ����
};

/************************************************************************************
* function : insertList
* description : Node�� �Է¹ް� �Է¹��� Node�� name�� ���Ͽ� ������������ student��
*				������ ������
* Variables : *temp - �Է¹��� ���� temp Node�� ����
*			  *p, *q - Node 2���� ����Ͽ� ���� ������ p�� �ϳ��� �Ѿ�� q�� p�� �ڸ�
*					  ���� temp�� ���� ������������ sort��
*************************************************************************************/
void List::insertList(char value, int num, string word, char abc) {
	Node *temp = new Node(value, num, word, abc); //������ Node�� temp�� ����
	Node *p = head;
	Node *q = 0;

	if (head == 0) { //head�� null�̸� temp���� head�� ����
		head = temp;
	}
	else if (temp->name < head->name) { //�Էµ� ���� ������������ sort��
		temp->next = head;
		head = temp; 
	}
	else {
		while ((p != 0) && (p->name < temp->name)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else
			q->next = temp;
	}

}

/***********************************************************************************
* function : searchGrade
* description : ���ϴ� ������ �Է��Ͽ� �Էµ� ������ �ش��ϴ� student�� ������ ���
* Variables : *p - head���� �ϳ��� �Ѿ�� �Էµ� ������ �ش�Ǵ� student�� ã��
***********************************************************************************/
void List::searchGrade(char abc) {
	Node *p;

	if (head != 0) { //����Ʈ�� ������� �ʰ�
		p = head;
		while (p != 0) { //p = 0�� �ƴϸ�
			if (p->grade == abc) { //���ϴ� ������ �ش��ϴ� student ��� ���
				cout << p->name << " ";
				cout << p->ID << " ";
				cout << p->major << " ";
				cout << p->grade << endl;
			}
			p = p->next;
		}
		cout << endl;
	}
	else 
		cout << "List Empty" << endl;
}

/*********************************************************************************
* function : searchMajor
* description : ���ϴ� ������ �Է��Ͽ� �Էµ� ������ �ش��ϴ� student�� ������ ���
* Variables : *p - head���� �ϳ��� �Ѿ�� �Էµ� ������ �ش�Ǵ� student�� ã��
**********************************************************************************/
void List::searchMajor(string word) {
	Node *p;

	if (head != 0) { //����Ʈ�� ������� �ʰ�
		p = head;
		while (p != 0) { //p = 0�� �ƴϸ�
			if (p->major == word) { //���ϴ� ������ �ش��ϴ� student ��� ���
				cout << p->name << " ";
				cout << p->ID << " ";
				cout << p->major << " ";
				cout << p->grade << endl;
			}
			p = p->next;
		}
	}
	else
		cout << "List empty" << endl;
}

/******************************************************************************
* function : list
* description : ����Ʈ�� ����� ��� student�� ������ ���
* Variables : *p - head���� �ϳ��� �Ѿ�� ����ؾ� �ϴ� ������ ã��
*******************************************************************************/
void List::list() {
	Node *p;

	if (head != 0) { //����Ʈ�� ������� �ʴٸ�
		p = head;
		while (p != 0) { //����� ���� ��� ���
			cout << p->name << " ";
			cout << p->ID << " ";
			cout << p->major << " ";
			cout << p->grade << endl;
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "List empty" << endl;
}

/**********************************************************************************
* funtion : merge
* description : ���� ���������� 2���� ���ļ� ���ο� ����Ʈ�� ������
* Variables : ll - ���������� 2���� ��ģ ������ ������ ����Ʈ
*			  *p - data1�� ������ head���� �ϳ��� �Ѿ�� ã��
*			  *q - data2�� ������ head���� �ϳ��� �Ѿ�� ã��
***********************************************************************************/

List List::merge(List a, List b) { //������ ���� 2���� ���ļ� List ll�� ����
	List ll;
	Node *p = a.head;
	Node *q = b.head;

	if (a.head != 0 || b.head != 0) { //List a�� b�� ������� �ʴٸ�
		while (p != 0) { //p�� null�� �ɶ����� data�� ����
			ll.insertList(p->name, p->ID, p->major, p->grade);
			p = p->next;
		}
		while (q != 0) {//q�� null�� �ɶ����� data�� ����
			ll.insertList(q->name, q->ID, q->major, q->grade);
			q = q->next;
		}
	}
	else
		cout << "List empty." << endl;

	return ll;
}

int main() {
	List A; //data1�� ���� ����Ʈ
	List B; //data2�� ���� ����Ʈ
	List C; //A�� B�� ���ļ� ������ ����Ʈ

	ifstream fin; 
	fin.open("data1.txt", ios::in);

	for (int i = 0; i < 7; i++) { //data1�� ������� ������ �ڷ������� A�� ����
		char a; int b; string c; char d;
		fin >> a >> b >> c >> d;
		A.insertList(a, b, c, d);
	}
	fin.close();

	fin.open("data2.txt", ios::in);

	for (int j = 0; j < 3; j++) { //data2�� ������� ������ �ڷ������� B�� ����
		char a; int b; string c; char d;
		fin >> a >> b >> c >> d;
		B.insertList(a, b, c, d);
	}

	//��� ����
	A.list(); //������ ���
	A.searchGrade('A'); //A ���� ���
	C = C.merge(A, B); //A����Ʈ�� B����Ʈ�� ���ļ� C����Ʈ�� ����
	C.searchMajor("CS"); //C����Ʈ���� CS������ ���
}