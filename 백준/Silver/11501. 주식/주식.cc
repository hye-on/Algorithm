#include<iostream>
#include<queue>

using namespace std;

int n,t;
int num[1000000];
priority_queue<pair<int, int>>q;
priority_queue<pair<int, int>>qT;
long long ans;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			q.push({ num[i],i });
		}
		int s = 0;
		while (!q.empty()) {

			int maxi = q.top().first;
			int idx = q.top().second;
			q.pop();
			if (idx <= s)
				continue;
			for (int i = s; i < idx; i++) {
				if (num[i] < maxi)
					ans += maxi - num[i];
			}
			s = idx;
		}
		q = qT;
		cout << ans << "\n";

	}
}