#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n;
int num[100001];
stack<pair<int, int>>sF;
stack<pair<int, int>>sB;
vector<pair<int,int>>ans; //개수, 인덱스
int main() {
	cin >> n;
	ans.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		ans[i].second = 10000000;
	}

	for (int i = 1; i <= n; i++) {
		
		while (!sF.empty() && sF.top().first<=num[i]) {
			sF.pop();
		}
		if (!sF.empty()) {

			ans[i].first = sF.size();
			ans[i].second = sF.top().second;
		}
		sF.push({num[i],i});
	}
	int tmp = 1000000;
	for (int i = n ; i>0; i--) {

		while (!sB.empty() && sB.top().first <= num[i]) {
			sB.pop();
		}
		ans[i].first += sB.size();
		if (!sB.empty()) {
			
			if (abs(sB.top().second - i) < abs(ans[i].second - i))
				ans[i].second = sB.top().second;
			
		}
		sB.push({ num[i],i });

	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i].first << " ";
		if (ans[i].first)
			cout<< ans[i].second;
		cout << "\n";
	}
}