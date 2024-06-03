#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int T;
int n;


int dp[2][100001];
int score[2][100001];

int main() {
	cin >> T;
	while (T--) {

		memset(dp, 0, sizeof(dp));
		memset(score, 0, sizeof(score));

		cin >> n;
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < n; i++) {
				cin >> score[k][i];
			}
		}

		//0열 먹기 ,1 열 먹기 db
		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];

		dp[0][1] = score[1][0] + score[0][1];
		dp[1][1] = score[0][0] + score[1][1];
		for (int i = 2; i < n; i++) {

			dp[0][i] = max(dp[1][i - 2] + score[0][i], dp[1][i - 1] + score[0][i]);
			dp[1][i] = max(dp[0][i - 2] + score[1][i], dp[0][i - 1] + score[1][i]);
			//cout <<i<<" " << dp[0][i] << "  " << dp[1][i] << endl;
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) <<"\n";

	}
}