#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int T;
int n, m;
//07:07 ~ 07:27

//1 누적합 444ms
//2 이분탐색

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	cin >> n;
	vector<int>a(n);
	vector<int>aSum(n);
	map<int, int>aM;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		t += a[i];
		aSum[i] = t;
		aM[aSum[i]]++;
		for (int j = 0; j < i; j++) {
			aM[aSum[i] - aSum[j]]++;
		}
	}

	cin >> m;
	vector<int>b(m);
	vector<int>bSum(m);
	vector<int>bV;

	map<int, int>bM;

	t = 0;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		t += b[i];
		bSum[i] = t;
		bV.push_back(bSum[i]);
		for (int j = 0; j < i; j++) {
			bV.push_back(bSum[i] - bSum[j]);
		}
	}

	//이분 탐색을 위해 정렬
	sort(bV.begin(), bV.end());

	//a 순회하면서 T-[a[i]] 존재하는지 찾기
	long long ans=0;
	for (auto it = aM.begin(); it != aM.end(); it++) {
		int vA = it->first;
		long long cntA = it->second;
		int fV = T - vA;
		
		auto it1 = upper_bound(bV.begin(), bV.end(), fV);
		auto it2 = lower_bound(bV.begin(), bV.end(), fV);
		ans += cntA * (it1 - it2);
	}

	cout << ans;
}