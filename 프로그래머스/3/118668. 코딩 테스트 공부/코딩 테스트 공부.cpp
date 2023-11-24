#include <string>
#include <vector>

using namespace std;

vector<vector<int>>dp(181,vector<int>(181,1000000));
int alp_p,cop_p,t;


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int pb_size = problems.size(); 
    int alp_max=0,cop_max=0;
    for(int i = 0;i<pb_size;i++){
        
            alp_max = max(alp_max, problems[i][0]);
            cop_max = max(cop_max, problems[i][1]);
        
    }
    //alp > alp_max, cop>cop_max일 수 있음
    dp[alp][cop]=0;
    dp[min(alp_max,alp)][cop]=0;
    dp[alp][min(cop_max,cop)]=0;
    dp[min(alp_max,alp)][min(cop_max,cop)]=0;
    
    //시작 인덱스를 min(alp_max,alp) 로 지정
    for(int i=min(alp_max,alp);i<=alp_max;i++){
        for(int j=min(cop_max,cop);j<=cop_max;j++){
            
            //알고리즘 공부해서 알고력 +1
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
            //코딩공부해서 코딩력 +1
            dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1);
            
            //문제 풀어서 둘다 +n (n>=0)
            for(int k=0; k < pb_size ;k++){
                //현재 알고력과 코딩력으로 풀 수 없는 문제는 스킵
               if(problems[k][0]>i || problems[k][1]>j)
                   continue;
                
               alp_p = problems[k][2];
               cop_p = problems[k][3];
               int x=min(i+alp_p, alp_max);
               int y =min(j+cop_p, cop_max);
                dp[x][y] = min(dp[x][y] , dp[i][j]+ problems[k][4] );
            }
        }
    }
    
    return answer= dp[alp_max][cop_max];
}