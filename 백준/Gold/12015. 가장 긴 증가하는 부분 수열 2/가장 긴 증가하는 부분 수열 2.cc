#include <iostream>
#include <vector>
using namespace std;


vector<int>dp;
int num;
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (dp.empty() || dp.back() < num)
			dp.push_back(num);
		else {
			auto idx = lower_bound(dp.begin(), dp.end(), num);
			dp[idx - dp.begin()] = num;
		}
	}

	cout << dp.size();

}