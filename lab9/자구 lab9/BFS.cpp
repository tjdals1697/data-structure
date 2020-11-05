#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;		//���Ϸκ��� �޴� ����� ����
const int ROW = 6;		//��
const int COL = 6;		//��
int matrix[ROW][COL] = { 0, };	//0���� matrix ���� 

class Node {
private:
	int vertex;		//data�� ��Ÿ����.
	Node* next;		//link�� ��Ÿ����.
public:
	Node(int num) :vertex(num), next(NULL) {}		//Node(int num)�� �����Ǹ� �ش� ����ü�� vertex(num), next(NULL)�� �ʱ�ȭ
	friend class Graph;
};

class Graph {
private:
	Node * graph[MAX];
	bool visited[MAX];
	Node* front;
	Node* rear;
public:
	Graph() :front(NULL), rear(NULL) {}		//Graph�� �����Ǹ� �ش� ����ü�� front(NULL) , rear(NULL)�� �ʱ�ȭ
	void Graph_graph_init();				//graph �迭�� NULL�� �ʱ�ȭ�ϴ� �Լ�
	void Graph_visited_init();				//visited �迭�� NULL�� �ʱ�ȭ�ϴ� �Լ�
	void Graph_insert(int num1, int num2);	//��带 insert�Ͽ� �׷��� ������ִ� �Լ�
	void Graph_display();					//��������� ������ִ� �Լ�
	void enqueue(int v);					//Queue�� ���� �־��ִ� �Լ�
	int dequeue();							//Queue���� ���� ���ִ� �Լ�
	void bfs(int v);						//BFS�� ������ִ� �Լ�
};

void Graph::Graph_graph_init()		//graph�迭�� NULL�� �ʱ�ȭ�����ش�.
{
	for (int i = 0; i < MAX; i++)
		graph[i] = NULL;
}

void Graph::Graph_visited_init()	//visited�迭�� NULL�� �ʱ�ȭ �����ش�.
{
	for (int i = 0; i < MAX; i++)
		visited[i] = 0;
}

void Graph::Graph_insert(int num1, int num2)// ��带 ������ �׷��� ����� ������ı��� �ϼ�
{
	if (graph[num1] == NULL)	//�ش� �迭[vertex]�� ����ִٸ� node �ֱ�
	{
		Node* temp_1 = new Node(num1);
		graph[num1] = temp_1;
	}
	if (graph[num2] == NULL)	//�ش� �迭[vertex]�� ����ִٸ� node �ֱ�
	{
		Node* temp_2 = new Node(num2);
		graph[num2] = temp_2;
	}

	//num1 ����� ������ next�� num2 ��� �߰�
	Node* p = graph[num1];
	Node* temp1 = new Node(num2); //num2 ��带 temp1�� ����
	while (p->next != NULL)		//������ ������ ã�ư�
		p = p->next;
	p->next = temp1;	//������ ��� p�� next�� temp1�� ��.

	matrix[graph[num1]->vertex][temp1->vertex] = 1;		//matrix�� �˸´� ����� 1�� ����

	//num2 ����� ������ next�� num1 ��� �߰� 
	p = graph[num2];
	Node* temp2 = new Node(num1);	//num1 ��带 temp2�� ����
	while (p->next != NULL)			//������ ������ ã�ư�
		p = p->next;
	p->next = temp2;		//������ ��� p�� next�� temp2�� ��.

	matrix[graph[num2]->vertex][temp2->vertex] = 1;		//matrix�� �˸´� ����� 1�� ����
}

void Graph::Graph_display()		//���� ��� ���
{

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::enqueue(int v)		//Queue�� ���� �־��ִ� �Լ�
{
	Node*temp = new Node(v);
	if (front == NULL)		//front�� NULL�� ���
	{
		front = temp;
		rear = temp;
	}
	else//front�� NULL�� �ƴ� ���
	{
		rear->next = temp;
		rear = temp;
	}
}

int Graph::dequeue()		//Queue���� ���� ���ִ� �Լ�
{
	Node* p;
	int v;
	p = front;		//p��忡 front�� ����
	front = p->next;	//front�� front�� ���� ��尡 �ȴ�.
	v = p->vertex;		//front ����� �� ����� p�� vertex ���� v�� �����Ѵ�.
	delete(p);			//p ��带 �����Ѵ�.
	return v;			//v�� ��ȯ�Ѵ�.
}

void Graph::bfs(int v) {
	Node* p;
	enqueue(v);				//Queue�� v�� �ִ´�.
	visited[v] = 1;			//visited[v]�� �湮 ǥ���Ѵ�.
	cout << v << " ";		//�湮�� �� ���

	while (front) {	//�ϳ��� vertex ��ξ� Ž��
		v = dequeue();	//dequeue�Լ����� ��ȯ �� ������ v ����
		for (p = graph[v]; p; p = p->next) {	//graph[v]���� next ���� ����
			if (!visited[p->vertex]) {	//�ش� ��尡 visited[p->vertex]�� �湮�� ���� ���ٸ�
				enqueue(p->vertex);		//p�� vertex�� Queue�� ����
				visited[p->vertex] = 1;		//p->vertex�� �湮ǥ��
				cout << p->vertex << " ";		//p�� vertex ���
			}
		}
	}
}


int main(void)
{
	Graph g;
	g.Graph_graph_init();			//graph�迭�� NULL�� �ʱ�ȭ �����ش�.
	g.Graph_visited_init();			//visited�迭�� NULL�� �ʱ�ȭ �����ش�.
	ifstream inStream;
	inStream.open("input1.txt");		//������ �о�´�.
	int num1, num2;
	for (int i = 0; i < MAX; i++)		//�ݺ������� ������ num1,num2�� ���ʴ�� �Է� �޾� �׷����� ������ش�.
	{
		inStream >> num1 >> num2;
		g.Graph_insert(num1, num2);
	}

	cout << "������� ���" << endl;
	g.Graph_display();			//��������� ����ϴ� �Լ��̴�.
	cout << endl;
	cout << "BFS ���" << endl;
	g.bfs(0);					//BFS�� ����ϴ� �Լ��̴�.
	cout << endl;

	inStream.close();
	return 0;
}