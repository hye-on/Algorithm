#include<iostream>
#include<queue>
using namespace std;
int N, K;
int answer;
int visit[100001];
void bfs() {
	
	queue<pair<int,int>>q;
	q.push({N,0});
	visit[N] = true;
	while (!q.empty()) {
		int n = q.front().first;
		int t = q.front().second;
		q.pop();
		
		if (n == K) {
			answer = t;
			break;
		}
		if (n + 1 <= 100000 && !visit[n + 1])
		{
			visit[n + 1] = true;
			q.push({ n + 1,t + 1 });
		}
		if (n - 1 >= 0 && !visit[n - 1]) {
			visit[n - 1] = true;
			q.push({ n - 1,t + 1 });
		}
		if (n * 2 <= 100000 && !visit[n * 2]) {
			visit[n *2 ] = true;
			q.push({ n * 2 ,t + 1 });
		}
	}
}

int main() {
	cin >> N >> K;
	bfs();
	cout << answer;
}