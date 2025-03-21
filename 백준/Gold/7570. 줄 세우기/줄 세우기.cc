#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ans;

int main() {
    
    cin>>N;
    vector<int>dp(N+1);
    
    int c=0;

    int maxN =0;
    for(int i=0;i<N;i++){
        cin>>c;
        dp[c] = dp[c-1]+1;
        maxN = max(maxN,dp[c]);
    }
    cout<<N-maxN;
    return 0;
}