#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
vector<vector<int>> edge;
vector<int>link[20001];
bool visit[20001];
map<int,int,greater<int>>cnt;
// 1번 부터 bfs
//dist 배열에 
vector<int>dist(20001);
void bfs(){
    queue<int>q;
    q.push(1);
    visit[1]=true;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        for(int i=0;i<link[node].size();i++){
            if(!visit[link[node][i]]){
                q.push(link[node][i]);
                dist[link[node][i]] = dist[node]+1;
                cnt[dist[link[node][i]]]++;
                visit[link[node][i]]=true;
            }
        }
        
    }
}

int solution(int n, vector<vector<int>> _edge) {
    int answer = 0;
    edge = _edge;
    for(int i=0;i<edge.size();i++){
        link[edge[i][0]].push_back(edge[i][1]);
        link[edge[i][1]].push_back(edge[i][0]);
        
    }
    bfs();
    // for(auto [a,b]:cnt)
    //     cout<<a<<" "<<b<<endl;
    return answer = cnt.begin()->second;
}