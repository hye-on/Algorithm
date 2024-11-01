#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include <climits>

using namespace std;

//다익스트라
//k번째 큰 수를 출력. k-1번째 까지는 우선순위큐에 저장

int n, p, k;

vector<pair<int,int>>link[1001];
int dist[1001];

bool dikstra(int mid) {


	priority_queue<pair<int,int>>pq; //mid 넘는 것의 개수, 노드 번호
	dist[1] = 0;

	// 
	pq.push({ 0,1});
	while (!pq.empty()) {
		int v = -1 * pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
	
		//이미 방문한 곳이면
		if (v > dist[cur])
			continue;
		
		for (int i = 0; i < link[cur].size(); i++) {
			int node = link[cur][i].first;
			int d = v + (link[cur][i].second > mid);
	
			
			if (dist[node] > d) {
				dist[node] = d;		
				pq.push({ -d,node });
			}

		}
	}	

	return dist[n] <= k;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p >> k;

	int a=0, b=0, v=0;
	for (int i = 0; i < p; i++) {
		cin >> a >> b >> v;
		link[a].push_back({ b,v });
		link[b].push_back({ a,v });
	}

	int start = -1, end = 10000001, mid=0;
	int ans = -1;
	while (start+1<end) {
		mid = (start + end) / 2;
		fill(dist, dist + 1001, INT_MAX);

		//가능하니 최소 비용을 줄여야함
		if (dikstra(mid)) {
			ans = mid;
			end = mid;
		}
		else {
			start = mid;
		}
	}

	cout << ans;
}