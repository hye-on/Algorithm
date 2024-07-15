#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

bool visit[200001];
int n, k;


int bfs() {
	queue<pair<int, int>>q;
	q.push({ n,0 });
	
	while (!q.empty()) {
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();

		if (cur == k) {
			return d;
		}
		//가중치가 작은 것을 먼저 방문하기 위해서
		int x = 2;
		while (cur * x < 200000 && visit[cur * x]==0) {
			q.push({ cur * x,d });
			visit[cur * x] = 1;
			x *= 2;
		}
		if (cur - 1 >= 0 && visit[cur - 1] == 0) {
			q.push({ cur - 1,d + 1 });
			visit[cur - 1] = 1;
		}

		if (cur + 1 < 100000 && visit[cur + 1]==0) {
			q.push({ cur + 1,d + 1 });
			visit[cur + 1] = 1;


		}
		

	}
}

int main() {
	cin >> n >> k;
	visit[n] = 1;
	cout<< bfs();
}