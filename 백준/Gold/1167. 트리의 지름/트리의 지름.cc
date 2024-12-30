#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool visit[100001];
vector<pair<int,int>>link[100001];
int maxCost = 0;  // 최대 비용 저장할 전역변수
int maxNode = 0;  // 최대 비용의 노드 저장할 전역변수

void dfs(int cur, int cost) {
    if(cost > maxCost) {
        maxCost = cost;
        maxNode = cur;
    }
    
    for(int i=0; i<link[cur].size(); i++) {
        int next = link[cur][i].first;
        int c = link[cur][i].second;
        
        if(visit[next])
            continue;
        
        visit[next] = true;
        dfs(next, cost + c);
        visit[next] = false;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    
    int to=0, from=0, cost=0;
    
    for(int i=0; i<N; i++) {
        cin >> from;
        while(true) {
            cin >> to;
            if(to == -1)
                break;
            cin >> cost;
            link[from].push_back({to, cost});
        }
    }

    visit[1] = true;
    dfs(1, 0);
    visit[1] = false;

    int start = maxNode;  
    maxCost = 0;  
    
    visit[start] = true;
    dfs(start, 0);
    visit[start] = false;

    cout << maxCost;
    
    return 0;
}