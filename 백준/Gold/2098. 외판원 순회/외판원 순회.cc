#include <iostream>
#include <cstring>
using namespace std;
int n;
int dp[16][1<<16];
int link[16][16];

#define MAX 160000000

int dfs(int cur, int visit){
    if(visit==(1<<n)-1){ // n이 5이면 32-1 , (1<<5)-1 , 11111 이 탐색 다한 것
        if(link[cur][0] == 0) 
            return MAX;
        return link[cur][0];
    }
    if(dp[cur][visit] != -1) 
            return dp[cur][visit];

    dp[cur][visit] = MAX;
    
    for(int i=0;i<n;i++){
        if(link[cur][i]==0)//길이 없음
            continue;
        if((visit & (1<<i))==(1<<i)) //방문한 적이 있음 11011 & 01000 -> 01000 == 01000
            continue;
        
        dp[cur][visit] = min(dp[cur][visit],link[cur][i] + dfs(i,visit |  1<<i));
    }
     return dp[cur][visit];
}
int main() {
   cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>link[i][j];
    }

    //dfs는 한번만 순회
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,1<<0);
    
    return 0;
}