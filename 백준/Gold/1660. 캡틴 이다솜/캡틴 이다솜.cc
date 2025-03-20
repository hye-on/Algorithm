#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = INT_MAX;

int N;
int arr[121], dp[300001];

int main()
{
    ios_base::sync_with_stdio(0); 
	cin.tie(0);

    for(int i=1; i<121; i++) 
    {
        arr[i] = i*(i+1)*(i+2) / 6; 
    }

    cin >> N;
    for(int i=1; i<300001; i++) dp[i]=i; 

    for(int i=1; i<121; i++)
    {
        for(int j=arr[i]; j<=N; j++)
        {
            dp[j] = min(dp[j], dp[j-arr[i]] + 1); 
        }
    }

    cout << dp[N];

    return 0;
}