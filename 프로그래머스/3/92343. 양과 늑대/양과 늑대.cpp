#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

//08:52
//0은 양, 1은 늑대
// visit처리 땜에 dfs

//양 쪽의 최대 양을 가져올 수 있는 개수

vector<int>link[17];
bool visit[17];
int maxS;
vector<int> info;
queue<int>sq;
void dfs(int node,int s, int w, queue<int>q){
    
    if(s<=w)
        return;
    if(s>maxS){
        maxS = s;
    }
    
    for(int i=0;i<link[node].size();i++){
        q.push(link[node][i]);
    }
        
    
    for(int i=0;i<q.size();i++){
         int next = q.front();
        q.pop();
      
        if(info[next]==0)
            dfs(next,s+1,w,q);
        else
            dfs(next,s,w+1,q);
        
        q.push(next);
    }
    
}
int solution(vector<int> _info, vector<vector<int>> edges) {
    int answer = 0;
    info = _info;
    for(int i=0;i<edges.size();i++){
        link[edges[i][0]].push_back(edges[i][1]);
    }
    
    dfs(0,1,0,sq);
    return maxS;
}