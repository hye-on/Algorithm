#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int N, K;
int cost[1001];
vector<int> edges[1001];  
int answer;
int dist[1001];            
int inDegree[1001];       

//위상정렬 풀이
void bfs(int start) {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            dist[i] = cost[i]; 
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : edges[cur]) {
            dist[nxt] = max(dist[nxt], dist[cur] + cost[nxt]);

            inDegree[nxt]--;
            if (inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    answer = dist[start];
}

int main() {
    cin >> T;

    while (T--) {
        cin >> N >> K; // 건물 개수, 간선 개수

        // 초기화
        for (int i = 1; i <= N; i++) {
            edges[i].clear();
            dist[i] = 0;
            inDegree[i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            cin >> cost[i];
        }

        int a, b;
        for (int i = 0; i < K; i++) {
            cin >> a >> b;
            edges[a].push_back(b);  
            inDegree[b]++;
        }

        int start;
        cin >> start;

        bfs(start);

        cout << answer << '\n';
    }

    return 0;
}
