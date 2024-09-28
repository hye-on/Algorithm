#include <iostream>
#include <queue>

using namespace std;
int n,k;
#define MAX 100000
int ans;
bool visit[MAX + 1];
int minD = MAX + 1;

void dijkstra(int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq; //오름 차순 시간,거리 
    pq.push({0,n});
    while(!pq.empty()){
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
         visit[cur] =true;
        if(cur==k && d<=minD){ 
            ans++;
            minD = d;
          continue;
        }
        if(d>minD)
            return;
       
        if(cur*2<=MAX && !visit[cur*2])
            pq.push({d+1,cur*2});
        if(cur+1<=MAX && !visit[cur+1])
            pq.push({d+1,cur+1});
        if(cur-1>=0 && !visit[cur -1])
            pq.push({d+1,cur-1});
        
    }
    
}
int main() {

    cin>>n>>k;
    dijkstra(n);
    cout<<minD<<endl;
    cout<<ans;
    return 0;
}