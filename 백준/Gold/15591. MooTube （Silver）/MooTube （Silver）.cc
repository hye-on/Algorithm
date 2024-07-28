#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n, q;
vector<pair<int,int>>num[5001];
int kk, v;
int ans;
bool visit[5001];


void bfs(int k, int start) {
	queue<int>q;
	q.push(start);
	visit[start] = true;
	
	while (!q.empty()) {
		int node = q.front();
		
		q.pop();
		for (int i = 0; i < num[node].size(); i++) {
			int next = num[node][i].first;
			int cost = num[node][i].second;
			if(visit[next])
				continue;
			if (cost >= k) {
				ans++;
				visit[next] = true;
				q.push(next);
			}

		}

	}
}
int main() {

	cin >> n >> q;
	int a=0, b=0, c=0;

	for (int i = 1; i <=n - 1; i++) {
		cin >> a >> b >> c;
		num[a].push_back({ b,c });
		num[b].push_back({ a,c });

	}
	
	while (q--) {
		
		cin >> kk >> v;
		bfs(kk, v);
		cout << ans << "\n";
		ans = 0;
		memset(visit, 0, sizeof(visit));
	}
	
}