#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>>v[50001]; //연결 노드 ,비용
int N, M;
int a, b, c;
int dist[50001];

void dijkstra() {
	priority_queue<pair<int, int>>pq; // // - 비용 , node
	pq.push({ 0,1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int currentN = pq.top().second;
		int cost = - pq.top().first; //현재 노드까지의 비용
		pq.pop();
		if (dist[currentN] < cost)
			continue;
		for (int i = 0; i < v[currentN].size(); i++) {
			int c = cost + v[currentN][i].second;
			if (c < dist[v[currentN][i].first]) {
				dist[v[currentN][i].first] = c;
				pq.push({ -c,v[currentN][i].first });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	fill(dist, dist + N + 1, 200000000);
	dijkstra();
	cout << dist[N];
	
}

