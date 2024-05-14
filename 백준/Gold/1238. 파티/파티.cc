#include<iostream>
#include<queue>
using namespace std;


int N, M, X;
int d[1001][1001];
vector<pair<int,int>>graph[1001];

int from, to, t;

void dijkstra(int start) {
	priority_queue<pair<int,int>>pq; //-비용, 현재노드

	pq.push({ 0,start });
	d[start][start] = 0;
	while (!pq.empty()) {

		int dist = -pq.top().first;
		int node = pq.top().second;

		pq.pop();
		if (d[start][node] < dist) //이미 구한 노드라면
			continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int cost = dist + graph[node][i].second;

			if (cost < d[start][graph[node][i].first]) {
				d[start][graph[node][i].first] = cost;
				pq.push({ -cost,graph[node][i].first });
			}
		}
	}

}
int main() {

	cin >> N >> M >> X;
	
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> t;
		graph[from].push_back({ to,t });

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <=N; j++) {
			
			d[i][j] = 1000000000;
		}
		
	}
	
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}

	
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		
		if (answer < d[X][i] + d[i][X])
			answer = d[X][i] + d[i][X];
	}
	cout << answer;

}