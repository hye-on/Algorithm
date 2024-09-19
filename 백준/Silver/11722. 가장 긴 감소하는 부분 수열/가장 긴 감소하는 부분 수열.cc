#include<iostream>
#include<algorithm>
using namespace std;

int num[1000];
int dp[1000];
int n;
int main() {
	cin >> n;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[j] > num[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(dp[i], ans);
	}
	cout << ans;
	
}