#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int T;
string s;
int az[26];
vector<vector<int>>v(26);
vector<vector<int>>vv(26);

int k;
int minN, maxN;
int main() {
	cin >> T;

	while (T--) {
		cin >> s;
		cin >> k;
		v = vv;
		memset(az, 0, sizeof(az));
		minN = s.size();
		maxN = 0;

		for (int i = 0; i < s.size(); i++) {
			az[s[i]-'a']++;
			v[s[i]-'a'].push_back(i);
		}
		bool isNoAnswer = true;
		for (int i = 0; i < 26; i++) {
			if (az[i] >= k)
				isNoAnswer = false;
		}
		if (isNoAnswer) {
			cout << "-1" << endl;
			continue;
		}
		
		for (int i = 0; i < 26; i++) {
			if (az[i] < k)
				continue;
			for (int j = 0; j <= az[i]-k; j++) {
				minN = min(minN, v[i][j + k - 1] - v[i][j] + 1);
				maxN = max(maxN, v[i][j + k - 1] - v[i][j] + 1);
			}
			
		}
		
		cout << minN << " " << maxN << endl;
	}
}