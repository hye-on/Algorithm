#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>>num(501);
int dp[501][501];

int N;
int a, b;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		num[i].first = a;
		num[i].second = b;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; i+j <= N; j++) {
			dp[j][j + i] = 2100000000;
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + num[j].first * num[k].second * num[i + j].second);
			}
		}
	}
	cout << dp[1][N];
}
