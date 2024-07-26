#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair<int, int>num[1001];
int maxi;
int idx;
int ans;
int high;
int stopIdx;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
		maxi = max(maxi, num[i].second);
	
	}
	sort(num, num + n);
	ans = (num[n - 1].first + 1 - num[0].first) * maxi;
	
	idx = 0;
	//왼쪽부터 
	for (int i = 1; i < n; i++) {
		if (num[i].second <= num[idx].second)
			continue;
		ans-= (num[i].first - num[idx].first)* (maxi - num[idx].second);
		idx = i;
		
		
	}
	stopIdx = idx;
	idx = n - 1;
	//오른쪽부터
	for (int i = n-2; i >=0; i--) {
		
		if (num[i].second <= num[idx].second)
			continue;
		ans -= (num[idx].first - num[i].first) * (maxi - num[idx].second);
	/*	if (stopIdx)
			break;*/
		idx = i;
	}
	
	cout << ans;

}