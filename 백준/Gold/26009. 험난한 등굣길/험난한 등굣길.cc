#include <iostream>
#include <algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

//06:00


//모든 정체구역을 표시해주면 시간초과
//경계만 표시해주기. 중심부를 기준으로 다이아몬드 크기
//최악 1500 * 루트2 * 4 * 3000  

//최적화 : 거리순으로 내림차순으로 정렬해서 안그려도 되면 패스

int n, m, k;
vector<vector<int>>map;
bool exAns;
bool OOB(int y,int x) {
	if (y >= n || y < 0 || x >= m || x < 0)
		return true;
	return false;
}

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void bfs() {
	
	queue<tuple<int,int,int>>q;
	q.push({ 0,0,0 });
	map[0][0] = 1;
	while (!q.empty()) {
		int curY = get<0>(q.front());
		int curX = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();

		if (curY == n - 1 && curX == m - 1) {
			cout << "YES" << "\n";
			cout << d;
			exAns = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (OOB(ny, nx) || map[ny][nx])
				continue;
			map[ny][nx] = 1;
			q.push({ ny,nx,d + 1 });
		}

	}

}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	cin >> k;
	vector<vector<int>>tmp(n,vector<int>(m,0));
	map = tmp;
	int a = 0, b = 0, c = 0;
	int MoveR[4] = { -1,1,1,-1 };
	int MoveC[4] = { 1,1,-1,-1 };
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		map[a-1][b-1] = 1;
		int NowR = a-1;
		int NowC = b - c-1;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < c; k++) {
				NowR += MoveR[j];
				NowC += MoveC[j];
				if ((NowR >= 0) && (NowR <= n-1) && (NowC >= 0) && (NowC <= m-1)) {
					map[NowR][NowC] = 1;
				}
			}
		}
		
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << map[i][j];
		cout << endl;
	}*/
	
	bfs();

	
	if (!exAns)
		cout << "NO";
}