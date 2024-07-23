#include<iostream>
#include<cmath>
using namespace std;

int n;
int num[31];
bool dp[31][15001];
int maxN;
int cur;
int ans;

void cal(int i, int w) {
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;
	cal(i + 1, w + num[i]);
	cal(i + 1, w);
	cal(i + 1, abs(w - num[i]));
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		maxN += num[i];
	}
	cal(0, 0);
	int t = 0,tmp=0;
	cin >> t;
	while (t--) {
		cin >> tmp;
		if (tmp > maxN)
			cout << 'N' << ' ';
		else if (dp[n][tmp])
			cout << 'Y' << ' ';
		else
			cout << 'N' << ' ';
	}
	
	
}