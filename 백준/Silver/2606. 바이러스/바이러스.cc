#include<iostream>
#include<queue>
using namespace std;


int N,M;
vector<int>com[101];
int a, b;
int visit[101];
int answer;
void bfs() {
	queue<int>q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int nc = q.front();
		q.pop();
		
		for (int i = 0; i < com[nc].size(); i++) {
			if (!visit[com[nc][i]]) {
				answer++;
				visit[com[nc][i]] = true;
				q.push(com[nc][i]);
			}
		}

	}
}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}
	bfs();
	cout << answer;

}