#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//10:25 ~10:47

int n;

int main() {
	cin >> n;
	vector<pair<int, int>>num(n);
	vector<int>dp(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
		dp[i] = 1;
	}

	sort(num.begin(), num.end());

	int mn = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j].first < num[i].first && num[j].second < num[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
				mn = max(dp[i], mn);

			}
		}
	}
	cout << n - mn;
}