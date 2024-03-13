#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>dp;
int num[1500001][2];
int n;


int main() {
	cin >> n;
	dp.resize(n + 51);
	for (int i = 1; i <= n; i++) {
		cin >> num[i][0] >> num[i][1];
		if (num[i][0] == 1)
			dp[i] = max(dp[i], num[i][1]);
		if (i + num[i][0] - 1 <= n)
			dp[i + num[i][0] - 1] = max(num[i][1], dp[i + num[i][0] - 1]);
		
	}
	
	for (int i = 1; i <= n; i++) {
		if (dp[i] < dp[i - 1])
			dp[i] = dp[i - 1];

		dp[i + num[i][0] - 1] = max(dp[i-1]+num[i][1], dp[i + num[i][0] - 1]);
	}
	
	cout << dp[n] << endl;
}