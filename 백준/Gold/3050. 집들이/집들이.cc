#include<iostream>
#include<algorithm>
using namespace std;


//완탐 1600 * 1600
int map[400][400];

int r, c,ans;

int dy[] = { 0,1,1 };
int dx[] = { 1,0,1 };
bool OOB(int y, int x) {
	if (y >= r || x >= c)
		return true;
	return false;
}

void findRectangle(pair<int,int>start) {
	int y = r;
	int x = c;
	for (int i = start.first; i < y; i++) {
		for (int j = start.second; j < x; j++) {
			if (map[i][j]) {
				x = j;
			}
			else {
				int headCnt = ((i - start.first + 1) + (j - start.second + 1)) * 2 - 1;
				ans = max(headCnt, ans);
			}
		}
	}

}

void bfs(pair<int, int>start) {

}
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

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!map[i][j]) {
				
				ans = max(ans,3);
				findRectangle({ i,j });
				
			}
		}
	}


	cout << ans;
}