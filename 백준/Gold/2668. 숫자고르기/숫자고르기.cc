#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int num[101];
vector<int>v;
int ans;
string tmp;
bool visit[101];
bool answer[101];

int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	int start = 0, end = 0 ;
	int idx = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		start = i;
		idx = i;
		cnt = 0;
		if (answer[i])
			continue;
		
		memset(visit, 0, sizeof(visit));

		if (visit[i])
			continue;
		
		visit[i] = true;
		while (true) {
			end = num[idx];
		
			if (cnt > n)
				break;
			cnt++;
			if (start == end) {
				ans += cnt;
				for (int i = 1; i <=n; i++) {
					
					if (visit[i]) {
						v.push_back({ i });
						answer[i] = true;
					}
					
				}
				break;
			}
			visit[end] = true;
			idx = end;

		}
	}
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (auto vv : v)
		cout << vv << endl;
}