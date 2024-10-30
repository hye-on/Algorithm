#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int T;
int n, m;
//07:07

//1 누적합

int main() {
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
	map<int, int>bM;

	t = 0;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		t += b[i];
		bSum[i] = t;
		bM[bSum[i]]++;
		for (int j = 0; j < i; j++) {
			bM[bSum[i] - bSum[j]]++;
		}
	}

	//a 순회하면서 T-[a[i]] 존재하는지 찾기
	long long ans=0;
	for (auto it = aM.begin(); it != aM.end(); it++) {
		int vA = it->first;
		long long cntA = it->second;
		int fV = T - vA;
		
		//찾는 값이 있으면
		if (bM.find(fV)!= bM.end()) {
			long long cntB = bM.find(fV)->second;
			ans += cntA * cntB;
		}
	}

	cout << ans;
}