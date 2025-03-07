#include <iostream>


using namespace std;

#define mod 10007

int dp[53][53]; //dp[13][3] -> 13C3
int N; 

int main(void){
    
  
    cin>>N;
    for(int i=0; i <= 52; i++){
        dp[i][0] = 1; dp[i][i] = 1; 
        for(int k = 1; k < i; k++){ //음수 안됨 
            dp[i][k] = dp[i-1][k-1] + dp[i-1][k];
            dp[i][k] %= mod;
            dp[i][i-k] = dp[i][k]; //대칭
        }
    }
    int anw = 0;
    for(int i=4; i<=N; i+=4){
        if( (i/4) % 2 == 1){ //카드 i/4쌍 뽑음. ex) 1쌍 뽑을 때 11112222, 22221111 2쌍을 뽑은 경우의수가 중복됨
            anw += dp[13][i/4] * dp[52-i][N-i];
        }
        else{
            anw -= dp[13][i/4] * dp[52-i][N-i];  // 2쌍을 뽑은 경우의수가 중복을 빼준다. 
        }
        anw %= 10007;
    }
    if(anw < 0) anw += mod;
    cout<<anw<<endl;
}