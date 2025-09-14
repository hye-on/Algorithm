#include <string>
#include <vector>

using namespace std;

//dp 
// 역삼각형 - (i-1) + (i-2)
// 위의 삼격형 - + (i-1)

int dp[200002]; 
int solution(int n, vector<int> tops) {
    int answer = 0;
    
    
    dp[1] = 1;
    dp[2] = 2;
    if(tops[0]==1)
        dp[2]++;
    for(int i=3;i<=n+n+1;i++){
        
        dp[i] = (dp[i-1] + dp[i-2])%10007;
        
        int top_idx = i/2 - 1;
        if(i%2==0 && tops[top_idx])
            dp[i] += dp[i-1]%10007;
    }
    

    return answer = dp[n+n+1];
}