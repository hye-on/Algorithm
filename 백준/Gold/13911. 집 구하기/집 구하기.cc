#include <iostream>
#include<vector>
#include <queue>
#include<algorithm>

using namespace std;
//조건 2개
// 맥,스 까지의 거리
// 최단거리

// 여러 정점을 한번에 다익스트라,
// 없으면 -1

//여러 간선 있을 수 있어서 최솟값으로 저장하기
#define MAX 1000000000
int V,E;
vector<pair<int,int>>edges[10001];

int mac_dist[10001];
int star_dist[10001]; 


void dijkstra(priority_queue<pair<int,pair<int,int>>>&pq){

    while(!pq.empty()){
        int d = - pq.top().first;
        int cur = pq.top().second.first;
        int ms = pq.top().second.second;
        bool isMac = ms==1? true:false;
        pq.pop();

        if(isMac && mac_dist[cur]<d)
            continue;
        if(!isMac && star_dist[cur]<d)
            continue;

        
        for(int i=0;i<edges[cur].size();i++){
            int nxt = edges[cur][i].first;
            int cost = edges[cur][i].second;
            if(isMac){
                
                if(d + cost < mac_dist[nxt]){
                    mac_dist[nxt] = d + cost;
                    pq.push({-(d+cost),{nxt,ms}});
                }
            }else{
                
                if(d + cost < star_dist[nxt]){
                    star_dist[nxt] = d + cost;
                    pq.push({-(d+cost),{nxt,ms}});
                }
            }
        }
    }
    
}
int main() {

    int u=0,v=0,w=0;

    cin>>V>>E;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    int mac=0,x=0;

    fill(mac_dist,mac_dist+10001,MAX);
    fill(star_dist,star_dist+10001,MAX);

    priority_queue<pair<int,pair<int,int>>>pq; // {비용,{노드, 스 or 맥}}

    
    cin>>mac>>x;
    int input_t=0;

    for(int i=0;i<mac;i++){
        cin>>input_t;
        mac_dist[input_t] = 0;
        pq.push({0,{input_t,1}});
    }

    int star =0, y =0;
    cin>>star>>y;
    
    for(int i=0;i<star;i++){
        cin>>input_t;
        star_dist[input_t] =0;
        pq.push({0,{input_t,2}});
    }

    dijkstra(pq);

    int ans=MAX;
    for(int i=1;i<=V;i++){
        if(mac_dist[i]==0 || star_dist[i]==0)
            continue;
        if(mac_dist[i]<=x&& star_dist[i]<=y){
            ans = min(ans, mac_dist[i] + star_dist[i]);
        }
    }
    if(ans==MAX)
        cout<<-1<<endl;
    else
        cout<<ans;
    return 0;
}