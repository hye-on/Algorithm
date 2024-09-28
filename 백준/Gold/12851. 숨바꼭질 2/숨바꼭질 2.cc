#include <iostream>
#include <queue>

using namespace std;
int n,k;
#define MAX 100000
int ans;
int visitCnt[MAX + 1];


void dijkstra(int n){
    queue<int>pq; 
    pq.push(n);
    while(!pq.empty()){
        int cur = pq.front();
        pq.pop();
        
        if(cur==k){ 
            ans++;
          continue;
        }
   
       
        if(cur+1<=MAX){
            if(visitCnt[cur+1]==0 || visitCnt[cur+1]== visitCnt[cur]+1){
                pq.push(cur+1);
                 visitCnt[cur+1]=visitCnt[cur]+1;
            }
        }
        if(cur-1>=0 ){
            if(visitCnt[cur-1]==0 || visitCnt[cur-1]== visitCnt[cur]+1){
                pq.push(cur-1);
                visitCnt[cur-1]=visitCnt[cur]+1;
            }
        }

         if(cur*2<=MAX){
            if(visitCnt[cur*2]==0 || visitCnt[cur*2]== visitCnt[cur]+1){
                pq.push(cur*2);
                visitCnt[cur*2]=visitCnt[cur]+1;
            }
        }
    }
    
}
int main() {

    cin>>n>>k;
    dijkstra(n);
    cout<<visitCnt[k]<<endl;
    cout<<ans;
    return 0;
}