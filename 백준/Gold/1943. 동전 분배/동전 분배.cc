#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T = 3;
int n;
int sum;
pair<int, int>v[101];
bool dp[50001];
int coin, cnt;

int main() {
	while (T--) {

		cin >> n;
		sum = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
			sum += v[i].first * v[i].second;
		}
		if (sum % 2 == 1) {
			cout << 0 << "\n";
			continue;

		}
		dp[0] = true;
		
		for (int i = 0; i < n; i++) {
			for (int j = sum / 2; j >=v[i].first; j--) {//j원을 만들 수 있는지
				//j-v[i].first원이 이미 존재하면 j-v[i].first + v[i].first = j원을 만들 수 있다.
				//dp[100]=true일 때 dp[300-200]은 true, 즉 200+100해서 300을 만들 수 있음.
				if (dp[j - v[i].first]) {
					for (int k = 0; k <v[i].second; k++) { // <이유는 이면 k==0일때 코인을 한개 쓴거인 금액이기 때문에
						if (j + v[i].first*k > sum / 2)break; //구할 필요가 없음
						dp[j + v[i].first * k] = true;
					}
				}
			}
		}
		cout << dp[sum / 2] << "\n";
	}
}