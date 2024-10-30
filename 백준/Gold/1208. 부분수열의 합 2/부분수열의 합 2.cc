#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,s;
//4:52
vector<int>v(40);

void calSum(int idx,int endIdx,int sum, vector<int>&vv) {

	if (idx == endIdx) {
		vv.push_back(sum);
		return;
	}

	calSum(idx + 1, endIdx, sum, vv);
	calSum(idx + 1, endIdx, sum+v[idx], vv);
}
int main() {
	cin >> n>>s;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int>left;
	vector<int>right;

	calSum(0, n /2, 0, left);
	calSum(n/ 2, n, 0, right);


	sort(right.begin(), right.end());

	
	
	long long ans = 0;
	for (int i = 0; i < left.size(); i++) {
		auto it1 = upper_bound(right.begin(), right.end(), s - left[i]);
		auto it2 = lower_bound(right.begin(), right.end(), s - left[i]);

		ans += it1 - it2;

		
	}
	if (s == 0)
		ans--;
	cout << ans;
}