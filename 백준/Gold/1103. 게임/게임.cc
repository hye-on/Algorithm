#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
string map[51];
int dp[51][51]; 
bool visited[51][51]; // 사이클 검사용

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int dfs(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m || map[y][x] == 'H') 
        return 0;
    
    if (visited[y][x]) {
        cout << -1;
        exit(0);
    }
    
    if (dp[y][x] != -1) 
        return dp[y][x];
    
    visited[y][x] = true;
    dp[y][x] = 0; 
    
    int move = map[y][x] - '0';
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * move;
        int nx = x + dx[i] * move;
        
        dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
    }
    
    visited[y][x] = false;
    return dp[y][x];
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> map[i];
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
    
    return 0;
}