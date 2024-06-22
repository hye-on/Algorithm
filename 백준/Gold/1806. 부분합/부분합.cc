#include<iostream>
#include<vector>
using namespace std;

int n, s;
//11:46
vector<int>num;
int sum;
int ans=100005;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}

	int idx = 0;
	for (int i = 0; i <n; i++) {

		
		sum += num[i];
		while (sum >= s && idx <= i) {
			sum -= num[idx];
			ans = min(ans, i - idx + 1);
			idx++;
		}
		
	}
	if (ans == 100005)
		ans = 0;

	cout << ans;
}