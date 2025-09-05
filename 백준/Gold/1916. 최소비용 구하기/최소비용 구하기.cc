#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// 최소비용 -> 다익스트라
int n,m;
 int start_point=0, end_point=0;
vector<vector<pair<int, int>>> graph;
vector<int> d; // 최단거리 테이블

// 10:00 ~

void dijkstra(int node){

    priority_queue<pair<int,int>>pq; //-비용, cur node

    pq.push({0,node});

    while(!pq.empty()){
        int dist = - pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now]<dist)
            continue;
        //인접 노드 확인
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second; // a->b , (a+c) + (c+b)
            if(cost< d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
        
    }
    
}

int main() {

    cin>>n;
    cin>>m;

    graph.resize(n+1);
    d.assign(n + 1, 100000001);
    
    int from=0, to=0, cost=0;
    
    for(int i=0;i<m;i++){
        cin>>from>>to>>cost;
        graph[from].push_back({to,cost});
    }
   
    cin>>start_point>>end_point;
    dijkstra(start_point);

    cout<<d[end_point];
    
    return 0;
}