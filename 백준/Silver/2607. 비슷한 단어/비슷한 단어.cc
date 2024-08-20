#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
string s,t;
int abcS[26];
int abcT[26];
int ans;
// 6,58
//빼기 - 차이로 알 수 있음
//더하기 - 차이로 알 수 있음

// 변하기 차이가 2이면 ㄱ 
// 
int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		abcS[s[i] - 'A']++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> t;
		for (int i = 0; i < t.size(); i++) {
			abcT[t[i] - 'A']++;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			cnt += abs(abcS[i] - abcT[i]);
		}
		if (s.size() != t.size() && cnt <= 1) 
			ans++;
		
		if (s.size() == t.size() && cnt <= 2)
			ans++;
		fill(abcT, abcT + 26, 0);
	}
	cout << ans;
}