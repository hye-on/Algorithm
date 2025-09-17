#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//10:24 ~10:47
//나가는것만 있고 들어오는게 없으면 정점
// 도넛: 나가는거 하나 들어오는거 하나
// 막대: 나가는것만 있는 노드, 들어오는것만 있는 노드 있음. or 아무것도 없거나
// 8자: 들어오는거 2개 나가는거 2개
vector<pair<int,int>>node_cnt(1000001); //나가는거, 들어오는거
bool visit[1000001];




vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.resize(4);
    int n=0;
    //초기화. 들어오는간선 나가는 간선 체크
    for(int i=0;i<edges.size();i++){
        int from = edges[i][0];
        int to = edges[i][1];
        
        node_cnt[from].first++;
        node_cnt[to].second++;
        n = max(n,from);
        n = max(n,to);
        visit[from] =true;
        visit[to] =true;
    }
    
    
    
    //정점 찾기
    for(int i=1;i<=n;i++){
        if(node_cnt[i].first>=2 && node_cnt[i].second==0){
            answer[0]=i;
            break;
        }
    }
    //정점과 관련된 간선 없애기
    int total =0;
    for(int i=0;i<edges.size();i++){
        if(edges[i][0]==answer[0]){
            node_cnt[edges[i][1]].second--;
            total++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!visit[i])
            continue;
        if(i==answer[0])
            continue;
        //스틱2
        if(node_cnt[i].first>=0 && node_cnt[i].second==0){
            answer[2]++;
            continue;
        }
            
         //8자3 
        if(node_cnt[i].first==2 && node_cnt[i].second==2)
            answer[3]++;
    }
    answer[1] = total - answer[2] - answer[3];
    
    return answer;
}