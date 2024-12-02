#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3001

using namespace std;

int n;
bool isCycleNode[MAX];          // 순환선에 속한 노드인지 저장
vector<int> graph[MAX];         // 인접 리스트
bool visited[MAX];
int parent[MAX];                // 이전 방문 노드(사이클 찾을 때 사용)
bool cycleFound;                // 사이클 발견 여부
int distToLoop[MAX];            // 순환선까지의 거리

// 순환선에서부터 각 노드까지의 거리 계산
void calculateDistance() {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));

    // 순환선에 속한 노드들을 시작점으로 큐에 추가
    for (int node = 1; node <= n; node++) {
        if (isCycleNode[node]) {
            visited[node] = true;
            q.push({node, 0});
        }
    }

    // BFS로 거리 계산
    while (!q.empty()) {
        int currentNode = q.front().first;
        int currentDist = q.front().second;
        q.pop();
        
        for (int nextNode : graph[currentNode]) {
            if (visited[nextNode]) continue;
            
            visited[nextNode] = true;
            distToLoop[nextNode] = currentDist + 1;
            q.push({nextNode, currentDist + 1});
        }
    }
}

// DFS로 순환선 찾기
void findCycle(int currentNode) {
    visited[currentNode] = true;

    for (int nextNode : graph[currentNode]) {
        if (cycleFound) return;  // 사이클을 이미 찾았으면 종료

        if (visited[nextNode]) {
            // 부모가 아닌 방문했던 노드를 만나면 사이클 발견
            if (nextNode != parent[currentNode]) {
                isCycleNode[currentNode] = true;
                cycleFound = true;

                // 사이클에 속한 노드들 표시
                int temp = currentNode;
                while (temp != nextNode) {
                    isCycleNode[parent[temp]] = true;
                    temp = parent[temp];
                }
                return;
            }
        }
        else {
            parent[nextNode] = currentNode;
            findCycle(nextNode);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    // 간선 입력
    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // 순환선 찾기
    findCycle(1);
    
    // 거리 계산
    calculateDistance();

    // 결과 출력
    for (int i = 1; i <= n; i++) {
        cout << distToLoop[i] << ' ';
    }

    return 0;
}