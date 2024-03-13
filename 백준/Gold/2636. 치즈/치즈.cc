#include<iostream>
#include<queue>
using namespace std;
int h,w;

int map[101][101]; // 1치즈, -1 공기 , 0 홀

int cnt, n,ansN; //cnt번 녹임. 마지막에 n 조각 남아있음
//bfs로 홀 세팅
void hole(int y,int x) {

	queue<pair<int, int>>q;
	q.push({ y,x });
	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };
	map[y][x] = 3;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ty = yy + dy[i];
			int tx = xx + dx[i];
			if (ty < 1 || ty >= h - 1 || tx < 1 || tx >= w - 1)
				continue;
			if (map[ty][tx] == 0) {
				q.push({ ty,tx });
				map[ty][tx] = 3;
			}
				
		}
	}

}
//접촉했을때 홀을 공기로 바꾸기



int main() {

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)//테두리
				map[i][j] = 3;
		}
	}

	for (int i = 1; i < h-1; i++) {
		if (map[i][1] == 0)
			hole(i, 1);
		if (map[i][w - 2] == 0)
			hole(i, w - 2);
	}
	for (int i = 1; i < w - 1; i++) {
		if (map[1][i] == 0)
			hole(1, i);
		if (map[h-2][i] == 0)
			hole(h-2, i);
	}
	
	/*cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
	//녹이기 옆에 3이 있으면 녹이기
	
	while (true) {
		/*cout << cnt << endl;
		cout << endl;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
		int dj[] = { 0,1,0,-1 };
		int di[] = { 1,0,-1,0 };
		for (int i = 1; i < h - 1; i++) {
			for (int j = 1; j < w - 1; j++) {
				if (map[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						if (map[i + di[k]][j + dj[k]] == 3) {
							map[i][j] = -1;
							break;
						}
					}
				}

			}
		}
		/*cout << "-1로" << endl;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
		cnt++;
		//다 녹였나 확인
		int tmp = 0;
		for (int i = 1; i < h - 1; i++) {
			for (int j = 1; j < w - 1; j++) {
				if (map[i][j] == 1)
					tmp++;
			}
		}
		if (tmp == 0) {
			//-1인걸로 bfs
			for (int i = 1; i < h - 1; i++) {
				for (int j = 1; j < w - 1; j++) {
					if (map[i][j] == -1)
						ansN++;
				}
			}
			break;
		}
		//녹였던 것 3으로 만들기
		for (int i = 1; i < h - 1; i++) {
			for (int j = 1; j < w - 1; j++) {
				if (map[i][j] == -1) {
					map[i][j] = 3;
					for (int k = 0; k < 4; k++) {
						if (map[i + di[k]][j + dj[k]] == 0) {
							hole(i + di[k], j + dj[k]);
							
						}
					}
				}
					
			}
		}
		
		/*cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
	}
	cout << cnt << "\n" << ansN;
	
}