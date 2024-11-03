#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;


//dp

int N,Q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	
	vector<int>v(N);
	for (int i = 0; i <N; i++) {
		cin >> v[i];
	}
	
	cin >> Q;
	vector<int>arr(Q + 1);
	int maxN = 0;
	
	for (int i = 1; i <= Q; i++) {
		cin >> arr[i];
		maxN = max(arr[i], maxN);
	}

	vector<int>dp(100001);
	
	//자기 자신을 만드는 방법
	for (int i = 0; i < N; i++)
		dp[v[i]] = 1;
	
	for (int i = 1; i <= maxN; i++) {
		//i를 만드는 방법이 없음
		if (dp[i] == 0)
			continue;

		int num = i * 2;
		while (num <= maxN) {

			dp[num] += dp[i];  //i==2 -> 4, 6, 8, 10 | i== 3 ->  3. 6. 9. 12 
			num += i;
		}
	}
	
	for (int i = 1; i <= Q; i++) {
		cout << dp[arr[i]] << " ";
	}

}