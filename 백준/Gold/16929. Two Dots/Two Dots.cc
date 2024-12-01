#include <iostream>
#include<cstring>
using namespace std;

int n, m;
char map[50][50];
bool visited[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int startX, startY;
bool dfs(int x, int y, char color,int depth) {
    visited[x][y] = true;
    

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (map[nx][ny] == color) {
            if (nx == startX && ny == startY && depth>=3) 
                return true;  
            if (visited[nx][ny])
                continue;
            if (dfs(nx, ny, color,depth+1)) return true;
        }
    }

    return false;
}

string solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                memset(visited, false, sizeof(visited));
                startX = i;
                startY = j;
                if (dfs(i, j , map[i][j],0)) return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    cout << solve();
    return 0;
}
