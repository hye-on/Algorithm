#include<iostream>
#include<map>
using namespace std;

map<string, int>m;
int n;
char cc;
string s;
int cnt;
int ans;
//Y 2, F 3, O 4
int main() {
	cin >> n >> cc;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (m[s] == 0)
			cnt++;
		m[s]++;
	}

	if (cc == 'Y') {
		ans = cnt ;
	}
	else if (cc == 'F') {
		ans = cnt / 2;
	}
	else {
		ans = cnt / 3;

	}

	cout << ans;
}