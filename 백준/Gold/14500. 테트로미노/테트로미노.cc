#include<iostream>
#include<algorithm>
using namespace std;

int map[502][502];
int visit[502][502];
int N, M;
int ans;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void dfs(int y, int x, int sum, int depth, int timestamp) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny <= 0 || ny > N || nx <= 0 || nx > M || visit[ny][nx] == timestamp)
            continue;

        visit[ny][nx] = timestamp;
        dfs(ny, nx, sum + map[ny][nx], depth + 1, timestamp);
        visit[ny][nx] = 0;  // Backtrack
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    int timestamp = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visit[i][j] = timestamp;
            dfs(i, j, map[i][j], 1, timestamp);
            timestamp++;
        }
    }

    // 'ㅗ' 
    int tmp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			 tmp = map[i][j] + map[i][j - 1] + map[i][j + 1] + map[i - 1][j] ;
			 ans = max(ans, tmp);
			 tmp = map[i][j] + map[i][j - 1] + map[i][j + 1]  + map[i + 1][j];
			 ans = max(ans, tmp);
			 tmp = map[i][j] + map[i][j - 1] + map[i - 1][j] + map[i + 1][j];
			 ans = max(ans, tmp);
			 tmp = map[i][j]  + map[i][j + 1] + map[i - 1][j] + map[i + 1][j];
			 ans = max(ans, tmp);
		}
	}

    cout << ans;
    return 0;
}
