#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

//5:00 ~ 

//다익스트라

int a,b,c;
int n,m;
int from,to;
int dist[100001];

void dijkstra(int start, vector<vector<pair<int,int>>>&link){
    priority_queue<pair<int,int>>pq;//비용, 노드

    pq.push({1000000001,start});
    dist[start]=1000000001;
    while(!pq.empty()){
        int d =  pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur]>d)
            continue;
       
        for(int i=0;i<link[cur].size();i++){
            int next = link[cur][i].first;
            int nextCost = min(link[cur][i].second,d);
          
            if(dist[next] < nextCost ){
               
                dist[next] = nextCost;
                pq.push({nextCost,next});
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<vector<pair<int,int>>>link(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        
        link[a].push_back({b,c});
        link[b].push_back({a,c});
    }
    cin>>from>>to;
   
    dijkstra(from,link);
    cout<<dist[to];
    return 0;
}