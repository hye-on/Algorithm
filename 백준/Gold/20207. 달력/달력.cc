#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<pair<int, int>>num;
int x, y;
bool map[1001][367];
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first) {
		if (a.second > b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main() {
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
	}
	sort(num.begin(), num.end(), cmp);

	//그리기
	int idx = 0;
	int s, e;
	int max_idx = 0;
	for (int i = 0; i < n; i++) {
		s = num[i].first;
		e = num[i].second;
		while (map[idx][s])
			idx++;
		for (int j = s; j <= e; j++) {
			map[idx][j] = true;
		}
		max_idx = max(e, max_idx);
		idx = 0;
	}
	//cout << "dd " << max_idx << endl;
	int  w1 = num[0].first, w2=0;
	bool chk = false;
	int start = num[0].first;
	int h = 0;
	int ans = 0;
	for (int i =w1 ; i <= max_idx+1; i++) {
		chk = false;
		for (int j = 0; j < n+1; j++) {
			if (map[j][i]) {
				chk = true;
				h = max(j,h);
			}
		}
		//계산
		if (!chk) {
			//cout<<start<<" " << i-1 <<" "<<h<< endl;
			ans += (i  - start) * (h + 1);
			start = i + 1;
			h = 0;
			
		}
	}
		
	cout << ans;
	
}