#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
int num[101];

int dp[101][51];
int answer;

int cal(int n, int m){
    if(m==0)
        return 0;
    if(n<=0)
        return -10000000;  
    if (dp[n][m] != -1) 
        return dp[n][m];

    int sum=0;
    dp[n][m] = cal(n-1,m); 

    for(int i=n;i>0;i--){
        sum+=num[i];
        int t = cal(i-2,m-1) + sum; // m-1개 + 1개
        dp[n][m] = max(t,dp[n][m]);
    }
    return dp[n][m];
}

int main() {
    cin>>N>>M;
    int s=0;
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }

    memset(dp,-1,sizeof(dp)); //true -> -1

    answer = cal(N,M);
    cout<<answer;
    return 0;
}