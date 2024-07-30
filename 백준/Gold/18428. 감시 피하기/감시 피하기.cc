#include<iostream>

using namespace std;
int n;
char num[6][6];
int visit[6][6];
pair<int,int> o[3];
string ans = "NO";
bool findAns = false;
bool TT(int y,int x) {
	for (int i = y-1; i >= 0; i--) {
		if (y == 0 && x == 3)
			cout <<"ddd " << num[i][x] << endl;
		if (num[i][x] == 'O')
			break;
		if (num[i][x] == 'S')
			return false;
	}
	for (int i = y+1; i < n; i++) {
		if (num[i][x] == 'O')
			break;
		if (num[i][x] == 'S')
			return false;
	}
	for (int i = x-1; i >= 0; i--) {
		if (num[y][i] == 'O')
			break;
		if (num[y][i] == 'S')
			return false;
	}
	for (int i = x+1; i < n; i++) {
		if (num[y][i] == 'O')
			break;
		if (num[y][i] == 'S')
			return false;
	}

	return true;
}
void check() {
	for (int i = 0; i < 3; i++) {
		num[o[i].first][o[i].second] = 'O';
	}
	
	//if (o[0].first == 0   ) {
	/*	cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << num[i][j] << " ";
			cout << endl;
		}
		cout << "d====================" << endl;*/
	//}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num[i][j] == 'T') {
				if (!TT(i, j)) {
					for (int i = 0; i < 3; i++) {
						num[o[i].first][o[i].second] = 'X';
					}
					return;
				}
			}
		}
	}
	ans = "YES";
	findAns = true;
	for (int i = 0; i < 3; i++) {
		num[o[i].first][o[i].second] = 'X';
	}
}

void backtracking(int y,int x, int depth) {
	
	if (findAns)
		return;
	if (y == n )
		return;
	if (depth == 3) {
		check();
		return;
	}
	
	for (int i = y; i < n; i++) {
		for (int j =0 ; j < n; j++) {
			if (visit[i][j])
				continue;
			if (num[i][j] != 'X')//선생이나 학생한테 장애물 놓을 수 없음
				continue;
			visit[i][j] = true;
			o[depth] = { i,j };
			if(j!=n)
				backtracking(i, j + 1,depth+1);
			else
				backtracking(i+1, 0, depth + 1);
			visit[i][j] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num[i][j];
		}
	}

	backtracking(0,0,0);
	cout << ans;
}