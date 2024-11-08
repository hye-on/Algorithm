#include<iostream>
#include<algorithm>

using namespace std;



int map[400][400];
int cnt[401][401];

int r, c,ans;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	char t = '.';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> t;
			map[i][j] = (t == '.') ? 0 : 1; //0: 빈칸, 1: 벽 
			
			
		}
	}

	//누적합
	for (int j = 0; j < c; j++) {
		for (int i = r-1;i >=0 ; i--) {
			if (!map[i][j])
				cnt[i][j] = cnt[i + 1][j] + 1;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!map[i][j]) {
				int h = cnt[i][j];
				for (int k = j; k < c; k++) {
					if (map[i][k])
						break;
					h = min(h, cnt[i][k]);
					ans = max(ans, 2 * (k - j + 1 + h)-1);
				}
				
			}
		}
	}


	cout << ans;
}