#include<iostream>
#include<queue>
using namespace std;


int N, M, X;
int d[2][1001];
vector<pair<int,int>>graph[2][1001];


int from, to, t;

void dijkstra(int start,int k) {
	priority_queue<pair<int,int>>pq; //-비용, 현재노드

	pq.push({ 0,start });
	d[k][start] = 0;
	while (!pq.empty()) {

		int dist = -pq.top().first;
		int node = pq.top().second;

		pq.pop();
		if (d[k][node] < dist) //이미 구한 노드라면
			continue;
		for (int i = 0; i < graph[k][node].size(); i++) {
			int cost = dist + graph[k][node][i].second;

			if (cost < d[k][graph[k][node][i].first]) {
				d[k][graph[k][node][i].first] = cost;
				pq.push({ -cost,graph[k][node][i].first });
			}
		}
	}

}
int main() {

	cin >> N >> M >> X;
	
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> t;
		graph[0][from].push_back({ to,t });
		graph[1][to].push_back({ from,t });

	}

	for (int i = 1; i <= N; i++) {
		
		d[0][i] = 1000000000;
		d[1][i] = 1000000000;
		
		
	}
	
	
	dijkstra(X, 0);
	dijkstra(X,1);
	

	
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		
		if (answer < d[0][i] + d[1][i])
			answer = d[0][i] + d[1][i];
	}
	cout << answer;

}