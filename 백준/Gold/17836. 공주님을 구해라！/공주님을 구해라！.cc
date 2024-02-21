#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> graph(101, vector<int>(101, 0));
vector<vector<int>> dist(101, vector<int>(101, 0));
int N, M, T;

int cnt, cnt_gram;
int ans;

void bfs() {

	queue<pair<int, int>> node;
	node.push({ 1,1 });
	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };
	while (!node.empty()) {
		
		int y = node.front().first;
		int x = node.front().second;
		graph[y][x] = 1;
		node.pop();
		if (y == N && x == M) {
			cnt = dist[y][x];
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			if (y + dy[i]<=0 || y + dy[i]>N || x + dx[i]<=0 || x + dx[i]>M)
				continue;
			if (graph[y + dy[i]][x + dx[i]] == 0) {
				node.push({ y + dy[i],x + dx[i] });
				graph[y + dy[i]][x + dx[i]] = 1;
				dist[y + dy[i]][x + dx[i]] = dist[y][x] + 1;
			}
			else if (graph[y + dy[i]][x + dx[i]] == 2) {
				cnt_gram = (dist[y][x] + 1) + (N - (y + dy[i])) + (M - (x + dx[i]));
				graph[y + dy[i]][x + dx[i]] = 1;
			}

		}
		
	}



}

int main() {
	cin >> N >> M >> T;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			
			cin >> graph[i][j];
		}
	}

	bfs();
	if (cnt == 0)
		ans = cnt_gram;
	else if (cnt_gram == 0)
		ans = cnt;
	else if (cnt < cnt_gram)
		ans = cnt;
	else if (cnt_gram <= cnt)
		ans = cnt_gram;
	
	if (ans == 0 || ans > T)
		cout << "Fail";
	else
		cout << ans;
	return 0;
}