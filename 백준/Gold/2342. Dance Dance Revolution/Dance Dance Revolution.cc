#include <bits/stdc++.h>

using namespace std;

//2:11
//그리디 or 완탐(bfs)
//멀티탭스케쥴링하고 비슷- 가중치가 있는 멀티탭 스케쥴링? 
//완탐 2의 100,000승 -> x
// 2 3 4 1
//중앙 -> 다른지점 2
// 같은 지점 1
// 옆 지점 3
//반대 지점 4

//dp 였다..
//상태는 6가지 가능 4*3/2
#define MAX 500000
int n;
int ans;
int idx;
int dp[100002][5][5];

int cost[5][5];

int main() {

    
    int initCnt=0;
    int a=0,b=0;

    cost[0][1] = 2;
    cost[0][2] = 2;
    cost[0][3] = 2;
    cost[0][4] = 2;

    cost[1][2] = 3;
    cost[2][3] = 3;
    cost[3][4] = 3;
    cost[4][1] = 3;
    
    cost[2][1] = 3;
    cost[3][2] = 3;
    cost[4][3] = 3;
    cost[1][4] = 3;

    cost[1][1] =1;
    cost[2][2] =1;
    cost[3][3] =1;
    cost[4][4] =1;

    cost[1][3] =4;
    cost[3][1] =4;
    cost[2][4] = 4;
    cost[4][2] =4;
    
    
    
    for(int i=0;i<100001;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                dp[i][j][k] =MAX;
            }
        }
    }

    dp[0][0][0]=0;
     while(true){  
        
        cin>>n;
        if(n==0)
            break;

        for(int i=0;i<=4;i++){
            for(int j=0;j<=4;j++){
               
                if(i==j && !(i==0 &&j==0))
                    continue;
                if(dp[idx][i][j]!=MAX){
                    //i를 움직여봄
                    dp[idx+1][n][j] = min(dp[idx+1][n][j], dp[idx][i][j] + cost[i][n]);
                    dp[idx+1][j][n] = dp[idx+1][n][j]; 
                    
                    //j를 움직여봄
                    dp[idx+1][i][n] = min(dp[idx+1][i][n], dp[idx][i][j] + cost[j][n]);
                    dp[idx+1][n][i] = dp[idx+1][i][n];
                }
            }
        }
       idx++;
     }  
    
    int answer = MAX;
    for(int i=0;i<=4;i++){
        for(int j=0;j<=4;j++){
            answer = min(answer, dp[idx][i][j]);
          //  cout<<i<<"  "<<j<<"  "<<dp[4][i][j]<<endl;
        }
    }
    

    cout<<answer;
    
    return 0;
}