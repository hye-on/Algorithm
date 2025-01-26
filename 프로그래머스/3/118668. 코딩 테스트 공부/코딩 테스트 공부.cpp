#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

// 케이스 3개 , 알고력, 코딩력, 문제풀기
// 알고력 범위 : max(초기 알고력,문제의 맥스 알고력) ~ max(초기알고력, 문제의 맥스 알고력)
// dp

int dp[181][181];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    int alp_max=0;
    int cop_max=0;
    
    //초기값 설정
    for(int i=0;i<problems.size();i++){
        int alp_req = problems[i][0];
        int cop_req = problems[i][1];
        
        alp_max = max(alp_max,alp_req);
        cop_max = max(cop_max,cop_req);
              
    }
    fill(dp[0],dp[181],2000000000);
    
    dp[alp][cop]=0;
    dp[min(alp_max,alp)][cop]=0;
    dp[alp][min(cop_max,cop)]=0;
    dp[min(alp_max,alp)][min(cop_max,cop)]=0;
    
    
    for(int i=min(alp_max,alp);i<=alp_max;i++){
        for(int j=min(cop_max,cop);j<=cop_max;j++){
        //알고력 높히기
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
        
        //코딩력 높히기
        dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1);
        
            //문제 풀기
            for(int k=0;k<problems.size();k++){
                int alp_req = problems[k][0];
                int cop_req = problems[k][1];
                
                int alp_rwd = problems[k][2];
                int cop_rwd = problems[k][3];
                
                int time = problems[k][4];
                if(alp_req>i || cop_req>j){
                    continue;
                }
                
                
                //이 부분 놓침  
                //구하는 것  80, 80 현재 70,70, 문제 풀었을때 20,20 얻으면 80,80에 반영안됨
                int x=min(i+alp_rwd, alp_max);
                int y =min(j+cop_rwd, cop_max);
                
                dp[x][y] = min(dp[x][y],dp[i][j]+time);
                
                
            }
            
           
        
        }
    }
    
  
    return answer = dp[alp_max][cop_max];
}