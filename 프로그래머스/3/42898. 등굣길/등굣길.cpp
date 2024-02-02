#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>>dp(101,vector<int>(101,0));


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto p :puddles){
        dp[p[1]][p[0]] = -1;
    }
    dp[1][1]=0;
    for(int i= 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j]<0)
                continue;
            if(i==1 && dp[i][j-1]<0)
            {   dp[i][j]=-1;
                continue;
            }
            if(j==1 && dp[i-1][j]<0)
            {   dp[i][j]=-1;
                continue;
            }
            if(i == 1 || j==1 && dp[i][j] == 0 )
            {   
                dp[i][j]=1;
                continue;
            }
           if(dp[i][j-1]>0)
               dp[i][j]+=dp[i][j-1];
            if(dp[i-1][j]>0)
                dp[i][j]+=dp[i-1][j];
            dp[i][j]%=1000000007;
            
        }
    }
    answer= dp[n][m];
    // for(int i= 1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return answer;
}