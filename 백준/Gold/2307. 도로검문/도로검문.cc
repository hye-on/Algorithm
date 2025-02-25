#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//3:37~ 4:36
//무한대이다. 이 경우에는 -1

// 다익스트라 먼저 하고 
// 최소 경로에서 한개씩 다 없애본다
// O(6000*10) -> 가능

#define MAX 500000001
int v,e;
vector<pair<int,int>>edges[1001];
pair<int,int>ban_edges; //{a,b} , {b,a} 둘다 ban

//경로를 어떻게 알아낼까?
//dist에 전 노드를 저장하고 역으로 추적하자

int dist[1001]; 
int prev_node[1001];
bool flag;
void dijkstra(){
    priority_queue<pair<int,int>>pq; // -거리,노드 
    pq.push({0,1});

    dist[1] =0;
    
    while(!pq.empty()){
        int d = - pq.top().first;
        int cur = pq.top().second;
        pq.pop();


        if(dist[cur]<d)
            continue;

        if(cur==v)
            break;

        for(auto edge : edges[cur]){
            int nxt = edge.first;
            int c = edge.second;
            int cost = d + c;
            // 검사하고 있는 도시 
            pair<int,int>cur_edges = {nxt,cur};
            pair<int,int>cur_edges2 = {cur,nxt};
   
            if(cur_edges== ban_edges || cur_edges2 == ban_edges)
                continue;
           
            if(cost<dist[nxt]){ // =?
                
                pq.push({-cost,nxt});
                dist[nxt] = cost;
                if(flag)
                    prev_node[nxt] = cur;
            }
            
        }
    }
}

int main() {
    cin>>v>>e;
    int a=0,b=0,d=0;
    
    for(int i=0;i<e;i++){
        cin>>a>>b>>d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
        
    }

    //다익스트라 해서 최소 경로 알아내기
    flag =true;
    fill(dist,dist+1001,MAX);
    dijkstra();
    //최소 경로 하나씩 ban시키면서 다익스트라 하고 지연시간 알아내기
    int cur_cost = dist[v];
   
    int ban_node=v;
    int answer = 0;
    flag = false;
    while(true){
        ban_edges = {ban_node,prev_node[ban_node]};
        //dist 초기화
        fill(dist,dist+1001,MAX);
        dijkstra();
      
        if(dist[v]==MAX){
            answer=-1;
            break;
            
        }
        answer = max(answer,dist[v]-cur_cost);
      
        if(prev_node[ban_node]==1)
            break;
        ban_node = prev_node[ban_node];
    }
   
    cout<<answer;

    return 0;
}