#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>home;
vector<int>gap;
int N, C;
int main() {
	cin >> N >> C;
	home.resize(N);
	gap.resize(N - 1);

	for (int i = 0; i < N; i++) {
		cin>>home[i];
	}
	sort(home.begin(), home.end());
	
	for (int i = 0; i < N - 1; i++) {
		gap[i] = home[i + 1] - home[i];
	}
	
	
	int cnt = 2,sum=0;
	bool chk = false, chk2 = false;
	int ans = 0;
	int left = 1, right = home[N - 1], mid = 0;
	while (left <= right) {
			mid = (left + right) / 2;
			sum = 0;
			cnt = 2;
			for (int i = 0; i < N - 1; i++) {
				sum += gap[i];
				if (sum >= mid) {
					cnt++;
					sum = 0;
				}
				
				
			}
			
			if (cnt == C && sum >= mid) {
				
				left = mid + 1;
				ans = max(mid, ans);
			}
			else if (cnt > C) {
				left = mid + 1;
				ans = max(mid, ans);
			}
			else {
				right = mid - 1;
			}
			
	}
	cout << ans;
}