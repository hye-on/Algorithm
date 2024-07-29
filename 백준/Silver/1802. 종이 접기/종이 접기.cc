#include<iostream>

using namespace std;

int t;
string ss;
bool ans;

 void cal(string s) {
	 if (s.size() == 1 || !ans)
		 return;
	int sh = s.size() / 2;

	for (int i = 0; i < sh; i++) {
		int b = s.size() - i - 1;
		if (s[i] == s[b]) {
			ans = false;
			break;
		}
	}
	cal(s.substr(0, sh));
	cal(s.substr(sh + 1, sh));
	
}
int main() {
	cin >> t;
	while (t--) {
		cin >> ss;
		ans = true;
		cal(ss);
		if (ans)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}