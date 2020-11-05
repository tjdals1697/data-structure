#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
	string name;
	int weight;
	int height;
	Node *next;
	Node *prev;
	Node(string n, int w, int h) {
		name = n;
		weight = w;
		height = h;
		next = 0;
		prev = 0;
	}
};

class List {
private:
	Node *head;
public:
	List() { head = 0; }
	bool isEmpty();
	void insertList(string n, int w, int h);
	void insertAfterNth(string n, int w, int h, int num);
	void Delete(string n);
	void forwardList();
	void backwardList();
	void searchList(string n);
	void findNth(int num);
};

bool List::isEmpty() {
	if (head == 0) return true;
	else return false;
}

void List::insertList(string n, int w, int h) {
	Node *temp = new Node(n, w, h);
	Node *p = 0;
	Node *q = 0;

	if (isEmpty()) {
		head = temp;
	}
	else if (temp->name < head->name) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		p = head;
		while (p != 0 && p->name < temp->name) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else {
			q->next = temp;
			temp->prev = q;
		}
	}
}

void List::insertAfterNth(string n, int w, int h, int num) {
	Node *temp = new Node(n, w, h);
	Node *p = head;
	Node *q = 0;
	
	if (isEmpty()) {
		head = temp;
	}
	else {
		for (int i = 0; i < num; i++) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else {
			q->next = temp;
			temp->prev = q;
		}
	}
}

void List::Delete(string n) {
	Node *p = 0;
	Node *q = 0;

	if (isEmpty())
		cout << "List is empty." << endl;
	else if (head->name == n) {
		if (head->next != 0) {
			p = head;
			head = head->next;
			head->prev = 0;
			delete p;
		}
		else
			head = 0;
	}
	else {
		p = head;
		while (p != 0 && p->name != n) {
			q = p;
			p = p->next;
		}
		if (p->next != 0 && p->name == n) {
			q->next = p->next;
			p->next->prev = q;
			delete p;
		}
		else if (p->next == 0 && p->name == n) {
			q->next = 0;
			delete p;
		}
		else
			cout << n << " is not in the list" << endl;
	}
}

void List::forwardList() {
	if (!isEmpty()) {
		Node *p = head;
		while (p != 0) {
			cout << p->name << " " << p->weight << " " << p->height << endl;
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "List is empty." << endl;
}

void List::backwardList() {
	if (!isEmpty()) {
		Node *p = head;
		while (p->next != 0)
			p = p->next;
		while (p != 0) {
			cout << p->name << " " << p->weight << " " << p->height << endl;
			p = p->prev;
		}
		cout << endl;
	}
	else
		cout << "List is empty." << endl;
}

void List::searchList(string n) {
	if (!isEmpty()) {
		Node *p = head;
		while (p != 0 && p->name != n) 
			p = p->next;
		if (p != 0)
			cout << "found" << endl;
		else
			cout << n << " is not in the list" << endl;
	}
	else
		cout << "List is empty." << endl;

	cout << endl;
}

void List::findNth(int num) {
	Node *p = head;
	int pos = 1;

	if (isEmpty())
		cout << "List is empty." << endl;
	else {
		while (p != 0) {
			if (pos == num) {
				cout << p->name << " " << p->weight << " " << p->height << endl;
				break;
			}
			p = p->next;
			pos++;
		}
		cout << endl;
		if (p == 0) {
			cout << num << " list is not in the list." << endl;
		}
	}
}

int main() {
	List A;

	ifstream fin;
	fin.open("data.txt", ios::in);

	for (int i = 1; i <= 4; i++) {
		string a; int b; int c;
		fin >> a >> b >> c;
		A.insertList(a, b, c);
	}
	fin.close();

	A.forwardList();
	A.searchList("lee");
	A.Delete("lee");
	A.forwardList();
	A.insertAfterNth("park", 73, 176, 2);
	A.forwardList();
	A.findNth(2);
	A.backwardList();
}