#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, d;
int dp[10001];
vector<pair<int, pair<int, int>>>num;
int a, b, c;


int main() {

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		num.push_back({ c,{a,b} });
	}

//	sort(num.begin(), num.end());

	for (int i = 0; i <= d; i++)
		dp[i] = i;

	for (int i = 1; i <= d; i++) {
		for (int j = 0; j < n; j++) {
			int st = num[j].second.first;
			int end = num[j].second.second;
			int dis = num[j].first;
			if (end == i) {
				dp[i] = min(dp[i], dp[st] + dis);
			}
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[d];
}