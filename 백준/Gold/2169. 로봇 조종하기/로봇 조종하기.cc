
#include<iostream>
#include<algorithm>
using namespace std;
int n ,m;

int dp[1002][1002];
int num[1001][1001];
int dp2[1002][1002];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num[i][j];
		}
	}

	fill(dp[0], dp[1002], -100000001);
	fill(dp2[0], dp2[1002], -100000001);

	dp[1][1] = num[1][1];
	dp2[1][1] = num[1][1];
	//첫번째 줄은 방법이 1개 뿐이다.
	
	for (int i = 2; i <=m; i++) {
		dp[1][i] = dp[1][i - 1] + num[1][i];
		dp2[1][i] = dp2[1][i - 1] + num[1][i];
 	}

	for (int i = 2; i <= n; i++) {
		//왼쪽과 위에 비교
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j] + num[i][j], dp[i][j - 1] + num[i][j]);
		}

		//오른쪽과 위에 비교
		for (int j = m ; j >= 1; j--) {
			dp2[i][j] = max(dp[i - 1][j] + num[i][j], dp2[i][j + 1] + num[i][j]);
		}

		//더 큰값으로 갱신
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i][j], dp2[i][j]);
			
		
		
	}

		cout << dp[n][m];
}