#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
using namespace std;
int V, E;

int from, to, v;
int node;
vector<pair<int,int>>map[20001];
priority_queue<pair<int, int>>pq;
//1:5
vector<int>dist(20001,2000000);
void dijkstra(int start) {

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int d = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		//이미 방문한 노드이면
		/*if (dist[current] < d)
			continue;*/
		for (int i = 0; i <map[current].size(); i++) {
				
			//현재 노드까지 거리 + 노드 거친 거리
			int next = map[current][i].first;
			int cost = d + map[current][i].second;
			if (cost < dist[next]) {
				dist[next] = cost;
				pq.push({ -cost,next });
			}
			
		}
	}

}
int main() {

	cin >> V >> E;

	cin >> node;
	
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> v;
		map[from].push_back({ to,v });
	}
	dijkstra(node);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 2000000)
			cout << "INF" << "\n";
		else
			cout << dist[i] << endl;

	}

}