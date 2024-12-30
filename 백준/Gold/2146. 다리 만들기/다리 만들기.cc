#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int answer = 1000;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};


void bfs(int y, int x, int fill_n, vector<vector<int>>& map) {
    queue<pair<int,int>>q;
    q.push({y,x});
    map[y][x] = fill_n;

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            
            if(ny>=N || ny<0 || nx>=N || nx<0)
                continue;
            if(map[ny][nx] == 1) {
                map[ny][nx] = fill_n;
                q.push({ny,nx});
            }
        }
    }
}

void findShortestBridge(int start_num, vector<vector<int>>& map) {
    queue<pair<pair<int,int>, int>> q;  // {{y, x}, dist}
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
   
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == start_num) {
                // 가장자리 체크
                for(int k=0; k<4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny>=0 && ny<N && nx>=0 && nx<N && map[ny][nx] == 0) { //0근처면 가장자리 
                        q.push({{i,j}, 0});
                        visited[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0 || ny>=N || nx<0 || nx>=N || visited[ny][nx])
                continue;
                
            if(map[ny][nx] == 0) {
                visited[ny][nx] = true; //같은 자리에 먼저 도달한것이 최소-> 방문 체크
                q.push({{ny,nx}, dist+1});
            }
            else if(map[ny][nx] != start_num) {
                answer = min(answer, dist);
                return;
            }
        }
    }
}

int main() {
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> map[i][j];

    // 섬 라벨링
    int fill_n = 2;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == 1)
                bfs(i, j, fill_n++, map);
        }
    }

    // 각 섬에서 다른 섬까지의 최단거리 찾기
    for(int num=2; num<fill_n; num++) {
        findShortestBridge(num, map);
    }

    cout << answer;
    return 0;
}