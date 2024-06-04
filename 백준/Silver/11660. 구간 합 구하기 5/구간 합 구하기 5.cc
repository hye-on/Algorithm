#include<iostream>
#include<vector>

using namespace std;
int N, M;
int num[1025][1025];
int dp[1025][1025];

int y, x, y2, x2;
int main() {

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num[i][j];
			if (i == 1 && j != 1)
				dp[i][j] = dp[i][j - 1] + num[i][j];
			else if (j == 1 && i != 1)
				dp[i][j] = dp[i - 1][j] + num[i][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + num[i][j] - dp[i - 1][j - 1];
		}
	}


	for (int i = 0; i < M; i++) {
		cin >> x >> y >> x2 >> y2;
		cout << dp[x2][y2] - dp[x-1][y2] - dp[x2][y-1] + dp[x-1][y-1] << "\n";

	}
	




}