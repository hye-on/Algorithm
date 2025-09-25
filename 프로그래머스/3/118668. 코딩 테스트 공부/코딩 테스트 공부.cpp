#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[181][181];
// 5 2   3 7
// 2 5   7 4
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int alp_max=0, cop_max=0;
    
    for(int i=0;i<problems.size();i++){
        alp_max = max(alp_max, problems[i][0]);
        cop_max = max(cop_max, problems[i][1]);
    }
    fill(dp[0],dp[181],2000000000);
    dp[alp][cop] =0;
    dp[min(alp,alp_max)][cop] =0;
    dp[min(alp,alp_max)][min(cop,cop_max)] =0;
    dp[alp][min(cop,cop_max)] =0;
    
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
    
    return answer;
}