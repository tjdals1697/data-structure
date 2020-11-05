#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int value) {
		data = value;
		next = 0;
	}
};

class List {
private:
	Node *head = 0;
public:
	List() {
		head = 0;
	}
	void insert(int num);
	void Delete(int num);
	void list();
	void search(int num);
	void PrintLast();
	void PrintNth(int num);
	void invertList();
	void quit();
};

void List::insert(int data) {
	Node *temp = new Node(data);
	Node *p = head;
	Node *q = 0;

	if (head == 0) {
		head = temp;
	}
	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else {
			q->next = temp;
		}
	}
}

void List::Delete(int num) {
	Node *p = head;
	Node *q = 0;

	if (head == 0)
		cout << "List is Empty" << endl;
	else if (head->data == num) {
		head = head->next;
		delete p;
	}
	else {
		while (p != 0 && p->data != num) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			q->next = p->next;
			delete p;
		}
		else {
			cout << num << " is not in the list" << endl;
		}
	}
}

void List::list() {
	Node *p;

	if (head != 0) {
		p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List empty!" << endl;
	}
}

void List::search(int num) {
	Node *p;

	if (head != 0) {
		p = head;
		while (p != 0 && p->data != num) {
			p = p->next;
		}
		if (p != 0) {
			cout << p->data << " is found." << endl;
		}
		else {
			cout << num << " is not in the list." << endl;
		}
	}
	else {
		cout << "List empty" << endl;
	}
}

void List::PrintLast() {
	Node *p;
	Node *q = 0;

	if (head == 0)
		cout << "List is Empty" << endl;
	else {
		p = head;
		while (p != 0) {
			q = p;
			p = p->next;
		}
		cout << q->data << endl;
	}
}

void List::PrintNth(int num) {
	Node *p = head;
	
	if (head == 0)
		cout << "List is Empty" << endl;
	else {
		p = head;
		for (int i = 0; i < num - 1; i++) {
			p = p->next;
		}
		if (p != 0)
			cout << p->data << endl;
		else
			cout << "Not found" << endl;
	}
}

void List::invertList() {
	Node *p = head;
	Node *q = 0;

	while (head) {
		q = p;
		p = head;
		head = head->next;
		p->next = q;
	}
	head = p;
	if (head != 0) {
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List empty!" << endl;
	}

	Node *i = 0; Node *j = 0;
	while (head) {
		j = i;
		i = head;
		head = head->next;
		i->next = j;
	}
	head = i;
}

void List::quit() {
	Node *p;

	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

int main() {
	List a;
	
	a.Delete(10);
	a.insert(10); a.insert(5); a.list();
	a.insert(30); a.search(5); 
	a.Delete(5); a.list();
	a.PrintNth(3);
	a.PrintLast();
	a.insert(40); a.invertList();
	a.quit();
}