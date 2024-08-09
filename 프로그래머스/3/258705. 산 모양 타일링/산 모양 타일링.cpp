#include <string>
#include <vector>
#include<iostream>
using namespace std;
int dp[200001];

int solution(int n, vector<int> tops) {
    int answer = 0;
    int total= n+n+1;
    int idx=0;
    
    dp[1]=1;
    dp[2]=2;
    if(tops[0])
        dp[2]++;
    for(int i=3;i<=total;i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;
        if(i%2==0){
            idx  = i/2-1;
            if(tops[idx]){
                dp[i]=(dp[i-1]*2+dp[i-2])%10007;
            }
        }
       
    }

   
    return dp[total];
}