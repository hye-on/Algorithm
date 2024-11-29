#include<iostream>
#include<algorithm>

using namespace std;


//9:58

int n;
int num[1000];
pair<int,int> dp[1000]; //dp[i].first i까지 증가하는 수열 길이
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		dp[i].first = 1;  
		dp[i].second = 1; 
		
	}
	int idx = n-1;

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i].first = max(dp[i].first, dp[j].first + 1);
			}
		}

		for (int j = n - 1; j > idx; j--) {
			if (num[j] < num[idx]) {
				dp[idx].second = max(dp[idx].second, dp[j].second + 1);
			}
		}
		idx--;
	}
	int answer = 0;

	for (int i = 0; i < n; i++) {
		answer = max(answer, dp[i].first + dp[i].second);
		
	}

	cout << answer - 1;

}