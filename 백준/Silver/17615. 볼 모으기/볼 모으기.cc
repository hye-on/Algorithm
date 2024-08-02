#include<iostream>
#include<algorithm>
using namespace std;
int n;
string s;

int redCnt;
int blueCnt;
int ans = 500001;

int main() {

	cin >> n;
	cin >> s;
	/*if (n == 1) {
		cout << 0;
		return 0;
	}*/
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R')
			redCnt++;
		else
			blueCnt++;
	}

	//각 옆에 연속 개수 세기
	ans = min(redCnt, blueCnt);
	int cntF = 1;
	
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i + 1])
			cntF++;
		else
			break;
	}
	if(s[0]=='R')
		ans = min(ans, redCnt - cntF);
	else
		ans = ans = min(ans, blueCnt - cntF);

	int cntB = 1;
	for (int i = n-1; i >0; i--) {
		if (s[i] == s[i - 1])
			cntB++;
		else
			break;
	}

	if (s[n-1] == 'R')
		ans = min(ans, redCnt - cntB);
	else
		ans = ans = min(ans, blueCnt - cntB);

	cout << ans;

}