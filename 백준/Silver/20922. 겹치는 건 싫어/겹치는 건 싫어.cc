#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int num[200001];
int cnt[100001];
int ans;
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> num[i];
	int j = 0;
	for (int i = 0;i < n; i++) {
		for (; j < n; j++) {

			
			if (cnt[num[j]] +1  > k) {
				ans = max(ans, j - i );
				break;
			}
			cnt[num[j]]++;
			if (j == n - 1)
				ans = max(ans, j - i + 1);
		}
		cnt[num[i]]--;
	}
	cout << ans;
}