#include<iostream>
#include<algorithm>

using namespace std;

int c, n;
int dp[100001];//i금액당 최대 고객
pair<int, int>num[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n;
	int cost = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
		cost = num[i].first;
		tmp = num[i].second;
		dp[cost] = tmp;
		for (int j = 2; tmp <= c ; j++) {
			tmp += num[i].second;
			dp[cost * j] = max(dp[cost*j],tmp );
		}
	}

	
	int ans = 0;
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < n; j++) {
			if(i - num[j].first>= 0)
				dp[i] = max(dp[i], dp[i-num[j].first] + num[j].second);

		}
		if (dp[i] >= c) {
			ans = i;
			break;
		}
	}

	cout << ans;
}