#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
// 12:16
//다익스트라
// 산봉우리 여러개 어떻게 -? 산봉우리 하나마다 다익스트라? 50000개인데? -> 한번에 끝내기?
#define MAX 10000001
vector<int>dist(50001,MAX); //[i] i번째에서 봉우리에서 최대 intensity
bool visit[50001];
vector<pair<int,int>>graph[50001]; //연결 저장

vector<int> answer;
set<int>gates;
set<int>summits;
priority_queue<pair<int,pair<int,int>>>q; //어느 봉우리에서 출발했는지, {현재 노드,intensity}
//intensity , <봉우리, 현재 노드>
void dijkstra(){
    
    
    int t=40;
    while(!q.empty()){
        
        int d = -q.top().first;
        int sum = q.top().second.first;
        int cur = q.top().second.second;
       
        q.pop();
       //  cout<<"d  "<<cur<<" "<<d<<" " <<dist[sum]<<endl;
        
        if(gates.find(cur)!=gates.end()){
            dist[sum] = min(dist[sum],d);
            continue;
        }
        if(visit[cur])
            continue;
        visit[cur] =true;
    
       if(d>dist[sum])
           continue;
       
        for(int i=0;i<graph[cur].size();i++){
            
            int node = graph[cur][i].first;
            int dis = graph[cur][i].second;
            
            if(summits.find(node)!=summits.end())
                continue;
            int cost = max(dis,d);
            if(cost>dist[sum])
                continue;
           q.push({-cost,{sum,node}});
                
          
            
        }
        
    }
    
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> _gates, vector<int> _summits) {
    answer.resize(2);
    answer[1] = 10000001;
    int a=0,b=0,w=0;
    
    for(int i=0;i<paths.size();i++){  
        a = paths[i][0];
        b = paths[i][1];
        w = paths[i][2];
        
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
   
    for(int i=0;i<_gates.size();i++){
        gates.insert(_gates[i]);
        
     }
    
    for(auto s : _summits){
        q.push({0,{s,s}});
        summits.insert(s);
    }
     dijkstra();
    
   for(int i=0;i<=n;i++){
       if(dist[i]==MAX)
           continue;
       if(dist[i]<answer[1]){
          
           answer[0] =i;
           answer[1] = dist[i];
       }
   }
   
    return answer;
}