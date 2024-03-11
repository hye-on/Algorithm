#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<regex>
using namespace std;
int T;
vector<string>number;
string ans;
int n;
string tmp;

int main() {
	cin >> T;
	bool chk = false;
	while (T--) {
		ans = "YES";
		cin >> n;
		number.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> tmp; 
			number[i] = regex_replace(tmp, regex(" "),"");//공백제거
		}
		sort(number.begin(), number.end());
		
		for (int i = 0; i < n-1; i++) {
			if (number[i + 1].size() < number[i].size())
				continue;
			if (number[i + 1].find(number[i]) == 0)
				ans = "NO";
			if (chk)
				break;
		}
		cout << ans << endl;
		chk = false;

	}
}
