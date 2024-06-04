#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int>m;
int N, M;
vector<string>v;
string s;
int cnt;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (m[s] == 1) {
			cnt++;
			v.push_back(s);
		}
	}
	cout << cnt << endl;
	sort(v.begin(), v.end());
	for (auto vv : v)
		cout << vv << endl;

}