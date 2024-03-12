#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
string from, to;
bool ans;


void cal(string s) {
	
	if (ans)
		return;
	if (s==from ) {
		ans = 1;
		return;
	}
	if (s.size()<=from.size())
		return;
	if (s.back() == 'A') {
		string tmp = s;
		cal(tmp.erase(tmp.size() - 1));

	}
	if (s.front() == 'B') {
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		cal(tmp.erase(tmp.size() - 1));
	}
		
	
}

int main() {
	cin >> from >> to;
	
	cal(to);
	cout << ans;

}