#include<iostream>

using namespace std;

int map[50][50][1001];
int r, c, t;
int cur, nCur;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int tmp1, tmp2;
void m(int y,int x, int tt) {
	cur = map[y][x][tt];
	nCur = cur/ 5;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			continue;
		if (map[ny][nx][0] == -1)
			continue;

		map[ny][nx][tt + 1] += nCur;
		map[y][x][tt] -= nCur;
	}
	
	map[y][x][tt + 1] += map[y][x][tt];
}

void clean(int tt) {
	for (int i = 0; i < r; i++) {
		if (map[i][0][0] == -1) {


			//공기 청정기로 들어감

			for (int k = i; k > 0; k--) {
				map[k][0][tt] = map[k - 1][0][tt];
			}
			for (int k = i + 1; k < r-1; k++) {
				map[k][0][tt] = map[k + 1][0][tt];
			}

			//왼쪽으로 당김
			for (int k = 0; k < c - 1; k++) {
				map[0][k][tt] = map[0][k + 1][tt];
				map[r - 1][k][tt] = map[r - 1][k + 1][tt];
			}

			//반대 벽쪽
			for (int k = 0; k < i ; k++) {
				map[k][c - 1][tt] = map[k + 1][c - 1][tt];
			}
			for (int k = r - 1; k > i + 1 ; k--) {
				map[k][c - 1][tt] = map[k - 1][c - 1][tt];
			}

			//오른쪽으로 당김
			for (int k = c - 1; k > 0; k--) {
				map[i][k][tt] = map[i][k - 1][tt];
				map[i + 1][k][tt] = map[i + 1][k - 1][tt];
			}
			map[i][1][tt] = 0; //공기 정화기에서 나온 애
			map[i + 1][1][tt] = 0; //공기 정화기에서 나온 애

			



		
			//공기 청정기 표시
			map[i][0][tt] = -1;
			map[i+1][0][tt] = -1;


			break;
		}

		
	}
}

int main() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j][0];
		}
	}

	for (int k = 0; k < t; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				
				if (map[i][j][k] > 0) {
					
					m(i, j, k);
					
				}
			}
		}
		
		clean(k + 1);
	}

	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j][t] > 0)
				sum += map[i][j][t];
		}
		
	}
	cout << sum;
}