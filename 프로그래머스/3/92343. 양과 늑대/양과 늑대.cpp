#include <string>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    // 그래프 구성
    vector<vector<int>> graph(n);
    for(auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    // {상태, 현재노드, 양의수, 늑대수}를 저장하는 큐
    queue<tuple<int,int,int,int>> q;
    // 방문한 상태를 저장하는 세트 {상태, 현재노드, 양의수}
    //늑대 수 저장 안해도 되는 이유는 : 방문한 노드랑 양의수랑 현재 노드가 같다면 늑대수도 이미 결정 된 상태일 것.
    set<tuple<int,int,int>> visited;
    
    // 초기 상태 (루트 노드는 항상 양)
    //초기 상태는 000001 -> 1 : 비트마스킹
    q.push({1, 0, 1, 0});
    
    visited.insert({1, 0, 1});
    
    int answer = 1;
    
    while(!q.empty()) {
        auto [state, cur, sheep, wolf] = q.front();
        q.pop();
        
        answer = max(answer, sheep);
        
        // 현재 방문 가능한 모든 노드들을 검사
        //자기 자식 노드뿐만 아니라 모든 노드들을 검사하므로 왔다 갔다 할 수 있게 됨. 
        for(int node = 0; node < n; node++) {
            //이미 방문한 노드들에서만 다음 노드를 탐색하도록 하는 코드
            //방문했던 노드에서 추가로 방문할 수 있는 노드만 탐색 :  0-> 1, 0->8 가능, 0->10 불가능
            if(!(state & (1 << node))) continue;  // 아직 방문하지 않은 노드 스킵
            
            // 현재 방문 가능한 노드에서 갈 수 있는 다음 노드들 검사
            for(int next : graph[node]) {
                if(state & (1 << next)) continue;  // 이미 방문한 노드 스킵
                
                int nextSheep = sheep + (info[next] == 0);
                int nextWolf = wolf + (info[next] == 1);
                
                if(nextWolf >= nextSheep) continue;  // 늑대가 양보다 많거나 같으면 스킵
                
                int nextState = state | (1 << next); //비트마스킹으로 방문 체크 
                auto nextTuple = make_tuple(nextState, next, nextSheep);
                
                if(visited.find(nextTuple) != visited.end()) continue;  // 이미 방문한 상태면 스킵
                
                visited.insert(nextTuple);
                q.push({nextState, next, nextSheep, nextWolf});
            }
        }
    }
    
    return answer;
}