#include<iostream>
#include<queue>

using namespace std;
int N, M, V;


int graph[1001][1001] = { 0 };
bool BFSisVisited[1001] = { false };
bool DFSisVisited[1001] = { false };
queue<int> q;

void dfs(int v)
{
	DFSisVisited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= N; i++)
	{
		if (graph[v][i] == 1 && DFSisVisited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
			dfs(i);
		}
	}
	
}
void bfs(int v) {
	q.push(v);
	BFSisVisited[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[v][i] == 1 && BFSisVisited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
				q.push(i);
				BFSisVisited[i] = true;
				cout << i << " ";
			}
		}
	}
}
int main()
{
	cin >> N >> M >> V;
	int a,b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;

	}
	dfs(V);
	cout << endl;
	bfs(V);
}