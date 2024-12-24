#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int from,to;
int dist[100001];

void dijkstra(int start, vector<vector<pair<int,int>>>& link){
    priority_queue<pair<int,int>> pq; //비용, 노드
    
    fill(dist, dist+n+1, 0);
    
    pq.push({2000000000,start});
    dist[start] = 2000000000;
    
    while(!pq.empty()){
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] > d)
            continue;
            
        for(auto& next : link[cur]){
            int nextNode = next.first;
            int nextCost = min(next.second, d);  
            
            if(dist[nextNode] < nextCost){
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    vector<vector<pair<int,int>>> link(n+1);
    
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        link[a].push_back({b,c});
        link[b].push_back({a,c});
    }
    cin >> from >> to;
   
    dijkstra(from,link);
    cout << dist[to];
    return 0;
}