#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//12:16
int n,ans,cnt;
int a, b;
vector<pair<int, char>>timeLine;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		timeLine.push_back({ a,'s' });
		timeLine.push_back({ b,'e' });
	}

	sort(timeLine.begin(), timeLine.end());

	for (int i = 0; i < n+n; i++) {
		if (timeLine[i].second == 's')
			cnt++;
		else
			cnt--;
		ans = max(ans, cnt);
	}
	cout<<ans;
}