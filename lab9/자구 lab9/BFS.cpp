#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;		//파일로부터 받는 노드의 갯수
const int ROW = 6;		//행
const int COL = 6;		//렬
int matrix[ROW][COL] = { 0, };	//0으로 matrix 구성 

class Node {
private:
	int vertex;		//data를 나타낸다.
	Node* next;		//link를 나타낸다.
public:
	Node(int num) :vertex(num), next(NULL) {}		//Node(int num)가 생성되면 해당 구조체를 vertex(num), next(NULL)로 초기화
	friend class Graph;
};

class Graph {
private:
	Node * graph[MAX];
	bool visited[MAX];
	Node* front;
	Node* rear;
public:
	Graph() :front(NULL), rear(NULL) {}		//Graph가 생성되면 해당 구조체를 front(NULL) , rear(NULL)로 초기화
	void Graph_graph_init();				//graph 배열을 NULL로 초기화하는 함수
	void Graph_visited_init();				//visited 배열을 NULL로 초기화하는 함수
	void Graph_insert(int num1, int num2);	//노드를 insert하여 그래프 만들어주는 함수
	void Graph_display();					//인접행렬을 출력해주는 함수
	void enqueue(int v);					//Queue에 값을 넣어주는 함수
	int dequeue();							//Queue에서 값을 빼주는 함수
	void bfs(int v);						//BFS를 출력해주는 함수
};

void Graph::Graph_graph_init()		//graph배열을 NULL로 초기화시켜준다.
{
	for (int i = 0; i < MAX; i++)
		graph[i] = NULL;
}

void Graph::Graph_visited_init()	//visited배열을 NULL로 초기화 시켜준다.
{
	for (int i = 0; i < MAX; i++)
		visited[i] = 0;
}

void Graph::Graph_insert(int num1, int num2)// 노드를 연결해 그래프 만들며 인접행렬까지 완성
{
	if (graph[num1] == NULL)	//해당 배열[vertex]가 비어있다면 node 넣기
	{
		Node* temp_1 = new Node(num1);
		graph[num1] = temp_1;
	}
	if (graph[num2] == NULL)	//해당 배열[vertex]가 비어있다면 node 넣기
	{
		Node* temp_2 = new Node(num2);
		graph[num2] = temp_2;
	}

	//num1 노드의 마지막 next에 num2 노드 추가
	Node* p = graph[num1];
	Node* temp1 = new Node(num2); //num2 노드를 temp1에 생성
	while (p->next != NULL)		//마지막 노드까지 찾아감
		p = p->next;
	p->next = temp1;	//마지막 노드 p의 next는 temp1이 됨.

	matrix[graph[num1]->vertex][temp1->vertex] = 1;		//matrix의 알맞는 행렬을 1로 수정

	//num2 노드의 마지막 next에 num1 노드 추가 
	p = graph[num2];
	Node* temp2 = new Node(num1);	//num1 노드를 temp2에 생성
	while (p->next != NULL)			//마지막 노드까지 찾아감
		p = p->next;
	p->next = temp2;		//마지막 노드 p의 next는 temp2가 됨.

	matrix[graph[num2]->vertex][temp2->vertex] = 1;		//matrix의 알맞는 행렬을 1로 수정
}

void Graph::Graph_display()		//인접 행렬 출력
{

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::enqueue(int v)		//Queue에 값을 넣어주는 함수
{
	Node*temp = new Node(v);
	if (front == NULL)		//front가 NULL일 경우
	{
		front = temp;
		rear = temp;
	}
	else//front가 NULL이 아닐 경우
	{
		rear->next = temp;
		rear = temp;
	}
}

int Graph::dequeue()		//Queue에서 값을 빼주는 함수
{
	Node* p;
	int v;
	p = front;		//p노드에 front를 복사
	front = p->next;	//front는 front의 다음 노드가 된다.
	v = p->vertex;		//front 노드의 전 노드인 p의 vertex 값을 v에 복사한다.
	delete(p);			//p 노드를 삭제한다.
	return v;			//v를 반환한다.
}

void Graph::bfs(int v) {
	Node* p;
	enqueue(v);				//Queue에 v를 넣는다.
	visited[v] = 1;			//visited[v]에 방문 표시한다.
	cout << v << " ";		//방문한 곳 출력

	while (front) {	//하나의 vertex 경로씩 탐색
		v = dequeue();	//dequeue함수에서 반환 된 값으로 v 수정
		for (p = graph[v]; p; p = p->next) {	//graph[v]부터 next 노드로 진행
			if (!visited[p->vertex]) {	//해당 노드가 visited[p->vertex]를 방문한 적이 없다면
				enqueue(p->vertex);		//p의 vertex를 Queue에 삽입
				visited[p->vertex] = 1;		//p->vertex를 방문표시
				cout << p->vertex << " ";		//p의 vertex 출력
			}
		}
	}
}


int main(void)
{
	Graph g;
	g.Graph_graph_init();			//graph배열을 NULL로 초기화 시켜준다.
	g.Graph_visited_init();			//visited배열을 NULL로 초기화 시켜준다.
	ifstream inStream;
	inStream.open("input1.txt");		//파일을 읽어온다.
	int num1, num2;
	for (int i = 0; i < MAX; i++)		//반복문으로 파일의 num1,num2를 차례대로 입력 받아 그래프를 만들어준다.
	{
		inStream >> num1 >> num2;
		g.Graph_insert(num1, num2);
	}

	cout << "인접행렬 출력" << endl;
	g.Graph_display();			//인접행렬을 출력하는 함수이다.
	cout << endl;
	cout << "BFS 출력" << endl;
	g.bfs(0);					//BFS를 출력하는 함수이다.
	cout << endl;

	inStream.close();
	return 0;
}