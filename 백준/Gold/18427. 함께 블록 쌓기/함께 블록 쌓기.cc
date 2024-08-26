#include<iostream>
#include<algorithm>

using namespace std;

int num[51][50];
int n, m, h;
int dp[51][50001];

int main() {
	cin >> n >> m >> h;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		int j = 0;
		do {
			cin >> tmp;
			num[i][j] = tmp;
			j++;
		} while (getc(stdin) == ' ');
		
	}


	
	
	for (int i = 0; i <= n; i++) 
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= h; j++) {
			for (int k = 0; k < 50; k++) {
				if (num[i][k] == 0)
					break;
				if (j >= num[i][k]) dp[i][j] = (dp[i][j] + dp[i - 1][j - num[i][k]]) % 10007;
			}
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 10007;
		}
	}
		
	
	cout << dp[n][h];
}