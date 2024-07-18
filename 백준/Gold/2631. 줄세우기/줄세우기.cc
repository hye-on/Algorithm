#include<iostream>
#include<algorithm>

using namespace std;
int n;
int num[201];
int dp[201];
int maxCnt;

//TODO 이분탐색으로 LIS풀어보기 : 이전문제 복습
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxCnt = max(dp[i], maxCnt);
	}

	cout << n - maxCnt;
}