#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int main() {
    cin>>n>>m;
    vector<int>cost(n+1);
    vector<int>sum(n+1); //dp i를 포함하는 최댓값
    vector<int>dp(n+1);


    for(int i=1;i<=n;i++){
        cin>>cost[i];
        sum[i] = sum[i-1] + cost[i];
    }

    int min_cost =0;
    int ans = 0;
    
    for(int i=m;i<=n;i++){
        min_cost = min(min_cost,sum[i-m]); // 1번쨰부터 연속된 최소값 (i-m전까지)
        dp[i] = sum[i] - min_cost;
        ans = max(dp[i],ans);
    }

    cout<<ans;
    return 0;
}