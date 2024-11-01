#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;

int main() {
    
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
   cin>>n>>k;
    
    vector<int>sum(n+1);
    int t =0,a=0;
    for(int i=1;i<=n;i++){
        cin>>a; 
        t += a;
        sum[i] =t; ///누적합
        
    }

    int ans=-1e7;
    for(int i=0;i+k<=n;i++){
        ans = max(sum[i+k]-sum[i],ans);
    }
    cout<<ans;
    return 0;
}