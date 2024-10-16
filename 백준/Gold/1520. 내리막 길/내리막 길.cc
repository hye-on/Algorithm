#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
//:3:37
using namespace std;

int N,M;
int graph[500][500];
int answer;
int cnt[500][500];
bool OOB(int Y,int X){
    if(Y>=M || Y<0 || X>=N || X<0)
        return false;
    return true;
}
void bfs(){
   priority_queue<pair<int,pair<int,int>>>q; // 이전 node값, y,x좌표 
    //높은애들 먼저 
    q.push({graph[0][0],{0,0}});
    int dx[] ={0,1,0,-1};
    int dy[] = {1,0,-1,0};
    cnt[0][0]=1;
    while(!q.empty()){
        int curY = q.top().second.first;
        int curX = q.top().second.second;
        int lastN = q.top().first;
        
        q.pop();
        // if(curY==M-1 && curX==N-1){
        //     continue;
        // }

        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if(!OOB(ny,nx))
                continue;
            if(graph[ny][nx]<lastN){
                //이미 방문한 적이 있다면 cnt만 높여주기
                if(cnt[ny][nx]){
                    cnt[ny][nx]+=cnt[curY][curX];
                }else{
                     q.push({graph[ny][nx],{ny,nx}});
                    cnt[ny][nx]=cnt[curY][curX];
                }
                
            }
               
        }
    }
    
}
int main() {

    cin>>M>>N;//세로 가로 
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>graph[i][j];
        }
    }
    bfs();
  
    
   cout<<cnt[M-1][N-1];
    return 0;
}