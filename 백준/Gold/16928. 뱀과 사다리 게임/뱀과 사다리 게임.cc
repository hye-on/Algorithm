#include <iostream>
#include<map>
#include<queue>
using namespace std;

int ans;
int n,m;

map<int,int>edges;
bool visit[101];

void bfs(){

    queue<pair<int,int>>q; // 노드 , 횟수
    q.push({1,0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

       
        if(cur==100){
            ans = cost;
            break;
        }

        
        for(int i=1;i<=6;i++){
            int nxt = cur+i;
            if(nxt>100 || visit[nxt])
                continue;
            if(edges[nxt]==0)
            {
                q.push({nxt,cost+1});
                visit[nxt] = true;
            }else{
                 q.push({edges[nxt],cost+1});
                visit[edges[nxt]] = true;
            }
        }
        
    }
}
int main() {
    cin>>n>>m;
    int a=0,b=0;
    
    for(int i=0;i<n+m;i++){
        cin>>a>>b;
        edges[a]=b;
    }

    bfs();
   cout<<ans;
    
    return 0;
}