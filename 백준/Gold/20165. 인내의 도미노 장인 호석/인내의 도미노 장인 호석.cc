#include<iostream>
#include<vector>

using namespace std;

int N, M, R;
int score;
int map[100][100];
bool chk[100][100]; //넘어지지 않은것 false, 넘어진것 true
// E, W, S, N
void attack(int y, int x, int d) {
	if (chk[y][x])
		return;
	score++;
	int n = map[y][x] - 1;
	chk[y][x] = true;
	bool st = true;
	while (n--) {
		//cout << "===" << endl;
		if (d == 'E') {
			x++;
		}
		else if (d == 'W') {
			x--;
		}
		else if (d == 'S') {
			y++;
		}
		else if (d == 'N') {
			y--;
		}
		if (x < 0 || x >= M || y < 0 || y >= N)
			break;
		
		if (!chk[y][x]) {
			score++;
			chk[y][x] = true;	
			//cout << y << " " << x << endl;
			if (map[y][x] > n+1)
				n += (map[y][x] - n);

		}

		
	}
}

void defend(int y, int x) {
	chk[y][x] = false;
}

int main() {

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int yy = 0, xx = 0;
	char d = 0;
	while (R--) {
		cin >> yy >> xx >> d;
		attack(yy - 1, xx - 1, d);
		cin >> yy >> xx;
		defend(yy - 1, xx - 1);
	}
	cout << score << endl;
	char ans = 'S';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (chk[i][j])
				ans = 'F';
			else
				ans = 'S';
			cout <<ans << " ";
		}
		cout << endl;
	}
	

}