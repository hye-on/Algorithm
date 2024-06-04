#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int map[1001][1001];
int sy, sx;
int n,m;
int tmp;
int visit[1001][1001];

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
void bfs() {
	queue<pair<pair<int,int>, int>>q;
	q.push({ {sy,sx},0 });
	
	visit[sy][sx] = 0;

	while (!q.empty()) {

		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visit[ny][nx] >=0)
				continue;
			
			visit[ny][nx] = d + 1;
			q.push({ {ny,nx},d + 1 });
				
		}


	}
}
int main() {
	cin >> n>>m;
	memset(visit, -1, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == 2) {
				sy = i; sx = j;
			}
			if (tmp == 0)
				visit[i][j] = 0;

			map[i][j] = tmp;

		}
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}