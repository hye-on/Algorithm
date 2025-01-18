#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//8:57
//bfs
int T;
int N,K;
int cost[1001];
vector<int>edges[1001];
int answer;
int dist[1001]; //max가 들어가야함

void bfs(int start){
    queue<pair<int,int>>q;
    q.push({start,cost[start]});
    dist[start] = cost[start];
   
    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();
      
        if(dist[cur]<d)
            continue;
        
        answer = max(answer,d);
        for(int i=0;i<edges[cur].size();i++){
            int nxt = edges[cur][i];
            int nxtCost = d + cost[nxt];
          
            if(dist[nxt]<nxtCost){
                dist[nxt] = nxtCost;
                q.push({nxt,nxtCost});
            }
        }
    }
}
int main() {
    cin>>T;
    while(T--){
        cin>>N>>K;//건물개수, 간선 개수
        for(int i=1;i<=N;i++)
            cin>>cost[i];

        int a=0,b=0;
        
        for(int i=0;i<K;i++){
            cin>>a>>b;
            edges[b].push_back(a);
        }
        int start=0;
        cin>>start;
        answer =0;
        fill(dist,dist+1001,0);
        bfs(start);
        for (int i = 1; i <= N; i++) {
            edges[i].clear();  
        }
        cout<<answer<<'\n';
        
    }
    return 0;
}