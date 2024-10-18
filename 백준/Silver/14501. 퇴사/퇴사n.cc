#include <iostream>
#include <algorithm>

using namespace std;
int n;
int day[16];
int cost[16];
int dp[16];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>day[i]>>cost[i];
    }

    int t=0;
    int ans=0;
    for(int i=n;i>=1;i--){
        t = i+day[i]; // 4일에 시작하여 3일 소요됨
        if(t<=n+1){//범위
            dp[i] = max(ans,cost[i]+dp[t]);
            ans = dp[i];
        }else{
            dp[i] = ans;
        }
    }
    cout<<ans;



    return 0;
}
