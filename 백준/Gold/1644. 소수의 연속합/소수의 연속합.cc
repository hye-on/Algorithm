#include<iostream>
#include<vector>
using namespace std;
int N;
bool num[4000001];
int cnt[4000001];
vector<int>v;
int ans;
int cntN;
int p1, p2;
int main() {
	//소수 구하기

	cin >> N;
	
	for (int i = 2; i*i<=N; i++) {
		if (num[i])
			continue;
		for (int j = i+i; j<=N; j+=i) {
			
			num[j] = true;
			
		}
	}
	for (int i = 2; i <=N; i++) {
		if (!num[i]) {
			
			v.push_back(i);
			cntN++;

		}
	}
	
	
	//투포인터
	int sum = 0;

	int idx = v.size() - 1;
	int s = 0, e = 0;

	while (1) {
		if (sum >= N)
			sum -= v[s++];
		else if (e == v.size())
			break;
		else 
			sum += v[e++];

		if (sum == N)ans++;
	}
	cout << ans;
}

