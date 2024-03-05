#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;
vector<int>num;


int max_n, ans;


int main() {
	cin >> N >> M;
	num.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> num[i];
		max_n = max(max_n, num[i]);
	}
	bool chk = false;
	int sum = 0;
	for (int i = 1; i <= max_n; i++) {//빗물 높이
		chk = false;
		sum = 0;
		for (int j = 0; j < M; j++) {
			if (num[j] >= i) {
				if (chk) {
					ans += sum;
					sum = 0;
				}
				chk = true;
			}	
			else {
				if (chk)
					sum++;
			}
		}
	}
	
	cout << ans;

}