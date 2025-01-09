#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;//지역의 수, 횡단보도의 주기

//주기를 돌면 안되고 몇초에 불이 들어오는지  계산 i+ tM
//다익스트라

#define INF 70000000001
vector<pair<int,int>>link[100001];
long long answer;
void bfs(int start){
    
    vector<long long>dist(n+1); //여러 노드를 걸쳐서 돌아왔을 때 시간이 더 작을 수 있음
    fill(dist.begin(),dist.end(),INF); 
    
    // 시간, 노드
    priority_queue<pair<long long,int>>pq; //그냥 q로 해야하나? 
    pq.push({0,start});
    
    dist[1]=0;
    
    while(!pq.empty()){
        long long time = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(node==n){
            answer = time+1;
            break;
        }
        if(node!=start && time>dist[node])
            continue;
  
        for(auto [next,idx] : link[node]){
          
            long long nt = idx;
            if(nt < time) {
                // time 이상이 되는 가장 가까운 주기 시간 계산
                nt = ((time - nt + m - 1) / m) * m + nt;
            }
            if(dist[next]>nt){
                
                dist[next] = nt;
                pq.push({-nt,next});
            }
        }
    
    }
}

int main() {
    cin>>n>>m;
   
    int a=0,b=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        link[a].push_back({b,i});
        link[b].push_back({a,i});
    }

    bfs(1);
    cout<<answer;

    return 0;
}