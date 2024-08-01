#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
vector<int>num(20);
int ans;
vector<int>v;
int idx;
int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		ans = 0;
		cin >> idx;
		for (int i = 0; i < 20; i++) {
			cin >> num[i];
			auto it = upper_bound(num.begin(), num.begin() + i , num[i]);
			if (it -num.begin() == i+1)
				continue;
			ans += i - (it-num.begin());
			num.insert(it, num[i]);
			
		}
		cout << t << " " << ans << "\n";

		
	}

}