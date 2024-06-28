#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<pair<int, int>>num; // 비용 , 메모리 
long long dp[10001]; //i비용당 최대 메모리
int a, b;
int ans;
int sCost = 0;


int main() {
	cin >> N >> M;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i].second;
	}
	for (int i = 0; i < N; i++) {
		cin >> num[i].first;
		sCost += num[i].first;;

	}


	for (int i = 0; i < N; i++) {
		for (int j = sCost; j >= num[i].first; j--) {
			dp[j] = max(dp[j], dp[j - num[i].first]+num[i].second);
		}

	}
	int tmp = 0;
	while (true) {
		if (dp[tmp] >= M) {
			
			ans = tmp;
			break;
		}
		tmp++;
	}

	cout << ans;
	
}