#include<iostream>
#include<cmath>
using namespace std;

int T;
int n;
int dp[10001];

int main() {
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i < 10001; i++) {
		
		dp[i] = dp[i - 3] + i/2 + 1;
	}
	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	
}