#include<iostream>
#include<queue>
using namespace std;

int n;
int depth;
int map[201][201];
int path[1001];
bool visit[201];

void bfs() {

	deque<pair<int, int>>q;// 현재 노드, next path idx
	q.push_front({ path[0],1 });
	while (!q.empty()) {
		
		//다음 루트 있으면 그것만 넣고 아니면 연결된 것 다 넣기
		int cur = q.front().first;
		int nextIdx = q.front().second;
		visit[cur] = true;
		
		q.pop_front();
		if (map[cur][path[nextIdx]] && !visit[path[nextIdx]]) {
			q.push_front({ path[nextIdx],nextIdx + 1 });
			continue;
		}

		for (int i = 1; i <= n; i++) {
			if (map[cur][i] && !visit[i]) {
				q.push_back({ i,nextIdx });
				
			}
		}

	}

}
int main() {
	cin >> n;
	cin >> depth;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < depth; i++) {
		cin >> path[i];
	}
	bfs();
	for (int i = 0; i < depth; i++) {
		if (!visit[path[i]]) {
			
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}