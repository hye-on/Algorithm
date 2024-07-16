#include<iostream>

using namespace std;

string s;
string window;
int ans = 2000000;
int cnt;
int main() {
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a')
			window += 'a';
	}
	int idx = 0;
	
	for (int i = 0; i < s.size(); i++) {
		cnt = 0;
		for (int j = 0; j < window.size(); j++) {
			idx = j + i;
			if (idx >= s.size())
				idx -= s.size();
			if (s[idx] != window[j])
				cnt++;
		}
		
		if (cnt < ans)
			ans = cnt;
	}
	cout << ans;
}