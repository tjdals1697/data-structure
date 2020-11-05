#include <iostream>
using namespace std;

#define V 7 //정점의 수
#define V2 8

int minDistance(int distance[], bool visited[]) { //최소 비용의 정점을 찾는 함수
	int min = INT_MAX, min_index; //최솟값 초기화

	for (int v = 0; v < V; v++)
		if (visited[v] == false && distance[v] <= min)	//방문하지 않은 정점이 최소 비용이면
			if (distance[v] != min)
				min = distance[v], min_index = v;
	return min_index; //최소 비용인 index값 반환
}

int minDistance2(int distance[], bool visited[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V2; v++)
		if (visited[v] == false && distance[v] <= min)	//방문하지 않은 정점이 최소 비용이면
			if (distance[v] != min)
				min = distance[v], min_index = v;
	return min_index;//최소 비용인 index값 반환
}

void shortest(int graph[V][V], int src) {
	int distance[V];
	bool visited[V];
	int savecost[V]; //최소 비용인 경로를 저장하는 배열

	for (int i = 0; i < V; i++) {
		savecost[0] = -1;
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[src] = 0;

	for (int count = 0; count < V - 1; count++) { //최단 경로 찾기
		int u = minDistance(distance, visited); //처리되지 않은 정점에서 최단 거리 가져오기

		if (count > 0)
			cout << "     Selected Node : " << u << " " << endl;

		visited[u] = true; //선택된 꼭지점 체크

		for (int v = 0; v < V; v++)

			if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
				savecost[v] = u;
				distance[v] = distance[u] + graph[u][v];
			}

		for (int i = 0; i < V; ++i)
			cout << distance[i] << " ";
	}
	for (int i = 0; i < V; ++i)
		if (visited[i] == false)
			cout << "     Selected Node : " << i << endl;
}

void shortest2(int graph[V2][V2], int src) {
	int distance[V2];
	bool visited[V2];
	int savecost[V2]; //최소 비용인 경로를 저장하는 배열

	for (int i = 0; i < V2; i++) { 
		savecost[0] = -1;
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[src] = 0; //시작 정점의 거리는 0

	for (int count = 0; count < V2 ; count++) { //최단 경로 찾기
		int u = minDistance2(distance, visited); //처리되지 않은 정점에서 최단 거리 가져오기
		visited[u] = true; //선택된 꼭지점 체크

		for (int v = 0; v < V2; v++)
			if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
				savecost[v] = u;
				distance[v] = distance[u] + graph[u][v];
			}

		if (u == src)
			cout << "Beginning Dist:   ";
		else
			cout << "Select:(" << u << ") dist:  ";

		for (int i = 0; i < V2; i++)
			cout << distance[i] << " ";
		cout << endl;
	}
	for (int i = 0; i < V2; i++) 
		if (visited[i] == false)
			cout << "  Selected Node : " << i << endl;
}

int main() {
	int graph[V][V] = {
	{ 100, 2, 4, 5, 100, 100, 100 },
	{ 100, 100, 100, 2, 7, 100, 100 },
	{ 100, 100, 100, 1, 100, 4, 100 },
	{ 100, 2, 1, 100, 4, 3, 100 },
	{100, 7, 100, 4, 100, 1, 5},
	{ 100, 100, 4, 3, 1, 100, 7 },
	{ 100, 100, 100, 100, 7, 5, 100 },
	};

	cout << "Cost matrix" << endl;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	shortest(graph, 0);
	cout << endl;

	int graph2[V2][V2] = {
	{0, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
	{300, 0, 10000, 10000, 10000, 10000, 10000, 10000},
	{1000, 800, 0, 10000, 10000, 10000, 10000, 10000},
	{10000, 10000, 1200, 0, 10000, 10000, 10000, 10000},
	{10000, 10000, 10000, 1500, 0, 250, 10000, 10000},
	{10000, 10000, 10000, 1000, 10000, 0, 900, 1400},
	{10000, 10000, 10000, 10000, 10000, 10000, 0, 1000},
	{1700, 10000, 10000, 10000, 10000, 10000, 10000, 0},
	};

	cout << "Cost matrix" << endl;
	for (int i = 0; i < V2; i++) {
		for (int j = 0; j < V2; j++)
			cout << graph2[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	shortest2(graph2, 4);
	cout << endl;
}