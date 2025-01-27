#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<iostream>

using namespace std;

//최단거리 다익스트라
//dist[i][state] i번째 방문 state 00101011일때 i에 도달하는 최단 경로
//
int d[1004][1024];
vector<pair<int,int>>adj[1004]; 
vector<pair<int,int>>adjrev[1004]; 
int trapidx[1004];
int answer = -1;

bool bitmask(int state,int cur){
    return (1<<trapidx[cur]) & state;
}
   
void dijkstra(int start,int end){
    
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    pq.push({d[start][0],start,0});
    
    while(!pq.empty()){
        int dist ,cur,state;
        tie(dist,cur,state) = pq.top();
        pq.pop();
         
        if(cur==end){
            answer  = dist;
            
            return;
        }
        
        if(d[cur][state] <dist)
            continue;
        
        //정방향 간선 확인
        for(auto p : adj[cur]){
            int nxt = p.first;
            int cost = p.second;
            int rev=0;
            //현재 트랩을 밟은 상태이면 뒤집음
            if(trapidx[cur] !=-1 && bitmask(state,cur))
                rev^=1;
            //다음 노드도 트랩이면 다시 상태를 뒤집음
            if(trapidx[nxt] != -1 && bitmask(state,nxt))
                rev^=1;
            //현재 있는 노드 or 다음 노드 중 1개만 밟았으면 정방향 간선이 뒤집어져 있음
            if(rev)
                continue;
            //두번이나 0번 밟았으면 뒤집어져 있지 않음
            int next_state = state;
            //다음 노드가 트랩이면 상태에 추가
            if(trapidx[nxt] != -1 )
                next_state ^= (1<<trapidx[nxt]);
            
            if(d[nxt][next_state] > cost + dist){
                d[nxt][next_state] = cost +dist;
                pq.push({d[nxt][next_state],nxt,next_state});
            }
            
        }
        
        //역방향 간선 확인
        for(auto p : adjrev[cur]){
            int nxt = p.first; 
            int cost = p.second;
            int rev=0;
            if(trapidx[cur]!=-1 && bitmask(state,cur)) rev^=1;
            if(trapidx[nxt]!=-1 && bitmask(state,nxt)) rev^=1;
            
            if(!rev)
                continue;
            int next_state = state;
            
            if(trapidx[nxt] !=-1)
                next_state ^= (1<<trapidx[nxt]);
            
            if(d[nxt][next_state] >cost + dist){
                d[nxt][next_state] = cost + dist;
                pq.push({d[nxt][next_state],nxt,next_state});
            } 
        }
    }
    
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    
    for(auto road : roads){
        int u = road[0];
        int v = road[1];
        int val = road[2];
        adj[u].push_back({v,val});
        adjrev[v].push_back({u,val});  //역방향     
    }
    
    fill(trapidx,trapidx+n+1,-1);
    
    for(int i=0;i<traps.size();i++){
        trapidx[traps[i]] =i;
    }
    
    for(int i=1;i<=n;i++)
        fill(d[i],d[i]+1024,30000000);
    
    d[start][0] =0;
    dijkstra(start,end);
    
    return answer;
}