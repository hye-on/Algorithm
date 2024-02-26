#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int map[301][301];
bool visit[301][301];



void dfs(int y ,int x) {

	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (next_y<0 || next_y>N || next_x<0 || next_x>M)
			continue;
		if (!visit[next_y][next_x] && map[next_y][next_x])
			dfs(next_y, next_x);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	int ans = 0;
	while (true) {
		//얼음 녹이고
		ans++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
			{
				cnt = 0;

				if (map[i][j]) {
					
					if (i - 1 >= 0 && map[i - 1][j]==0)
						cnt++;
					if (i < N && map[i + 1][j]==0)
						cnt++;
					if (j - 1 >= 0 && map[i][j-1]==0)
						cnt++;
					if (j + 1 < M && map[i][j + 1]==0)
						cnt++;
					map[i][j] -= cnt;
					if (map[i][j] <= 0)
						map[i][j] = -1;
					

				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == -1)
					map[i][j] = 0;
			}
		}
		

		//개수 세고
		int chunk = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] && !visit[i][j]) {
					dfs(i, j);
					chunk++;
				}
			}
		}
		memset(visit, false, sizeof(visit));
		
		if (chunk >=2)
			break;
		if (chunk==0) {
			ans = 0;
			break;
		}
	}

	cout << ans;
	
}