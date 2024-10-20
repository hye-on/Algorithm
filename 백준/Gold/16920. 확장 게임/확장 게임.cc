#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, p;
vector<int>s;
queue<pair<pair<int, int>, int>>pos[10]; //위치, 거리
char map[1000][1000];
vector<int> castle; // 각 플레이어의 성 개수

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void bfs(int node) {
    queue<pair<pair<int, int>, int>> next_pos;

    while (!pos[node].empty()) {
        int curY = pos[node].front().first.first;
        int curX = pos[node].front().first.second;
        int d = pos[node].front().second;
        pos[node].pop();

        for (int i = 0; i < 4; i++) {
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if (ny >= n || ny < 0 || nx >= m || nx < 0)
                continue;

            if (map[ny][nx] != '.')
                continue;

            map[ny][nx] = node + '0';
            castle[node]++;

            if (d + 1 == s[node]) {
                next_pos.push({ {ny, nx}, 0 });
            }
            else {
                pos[node].push({ {ny, nx}, d + 1 });
            }
        }
    }

    //다음 확장을 시작할 위치 
    pos[node] = next_pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    s.resize(p + 1);
    castle.resize(p + 1, 0);

    for (int i = 1; i <= p; i++)
        cin >> s[i];

    string str = "";
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j];
            if (map[i][j] - '0' > 0 && map[i][j] - '0' < 10) {
                int player = map[i][j] - '0';
                pos[player].push({ {i,j}, 0 });
                castle[player]++;
            }
        }
    }

    bool changed;
    do {
        changed = false;
        vector<int> prev_castle = castle;

        for (int i = 1; i <= p; i++) {
            if (!pos[i].empty()) {
                bfs(i);
            }
        }

        // 이전 턴과 비교하여 변화가 있는지 확인
        for (int i = 1; i <= p; i++) {
            if (prev_castle[i] != castle[i]) {
                changed = true;
                break;
            }
        }
    } while (changed);

    for (int i = 1; i <= p; i++)
        cout << castle[i] << " ";

    return 0;
}