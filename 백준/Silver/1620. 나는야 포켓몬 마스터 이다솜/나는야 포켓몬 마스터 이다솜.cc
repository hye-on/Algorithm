#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int n, m;

map<string, int>m1;
map<string, string>m2;
vector<string>ans;

int main() {
	cin >> n >> m;
	string s = "";
	for (int i = 0; i < n; i++) {
		cin >> s;
		
		m1[s] = i + 1;
		m2[to_string(i + 1)] = s;
	}
	string s2 = "";
	
	for (int i = 0; i < m; i++) {
		cin >> s2;

		if (s2[0] > '0' && s2[0] <= '9') {
			ans.push_back(m2[s2]);
		}
		else {
			ans.push_back(to_string(m1[s2]));

		}
	}
	for (auto a : ans)
		cout << a << '\n';
}