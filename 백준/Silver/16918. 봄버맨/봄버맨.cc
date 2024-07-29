#include<iostream>

using namespace std;
int r, c, n;
int map[201][201];
char tmp;
#define MAX 205
int main() {
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> tmp;
			if (tmp == '.')
				map[i][j] = MAX;

		}
	}

	//2초부터 상태 변화가 있음
	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };
	for (int s = 2; s <=n; s++) {


		if (s>2 && (s -3) % 2 == 0) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (s - map[i][j] == 3) {
						map[i][j] = MAX;
						for (int k = 0; k < 4; k++) {
							int ny = i + dy[k];
							int nx = j + dx[k];
							if (ny < 0 || ny >= r || nx < 0 || nx >= c)
								continue;
							if (s - map[ny][nx] != 3)
								map[ny][nx] = MAX;
						}
					}
				}
			}
			continue;
		}
		
	


		//폭탄 설치
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == MAX)
					map[i][j] = s;
			}
		}
		




	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != MAX)
				cout << 'O';
			else
				cout << '.';

		}
		cout << endl;
	}

}