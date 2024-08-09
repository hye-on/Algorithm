#include<iostream>

using namespace std;
// 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
//칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0
//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
int map[21][21];
int N, M, X, Y, K;
struct Dice{
	int t;//위
	int b;//아래
	int e;//동쪽
	int w;//서쪽
	int n;//북
	int s;//남

};

//주사위 선언
Dice dice = { 0,0,0,0,0,0 };


void toE() {

	if (X + 1 >= M)
		return;
	X++;
	int tmp = dice.b;
	dice.b = dice.e;
	dice.e = dice.t;
	dice.t = dice.w;
	dice.w = tmp;
	
	if (map[Y][X] == 0) {
		map[Y][X] = dice.b;
	}
	else {
		dice.b = map[Y][X];
		map[Y][X] = 0;
	}
	cout << dice.t << "\n";

}
void toW() {
	if (X - 1 < 0)
		return;
	X--;
	int tmp = dice.b;
	dice.b = dice.w;
	dice.w = dice.t;
	dice.t = dice.e;
	dice.e = tmp;

	if (map[Y][X] == 0) {
		map[Y][X] = dice.b;
	}
	else {
		dice.b = map[Y][X];
		map[Y][X] = 0;
	}

	cout << dice.t << "\n";

}
void toN() {
	if (Y - 1 < 0)
		return;
	Y--;
	int tmp = dice.b;
	dice.b = dice.n;
	dice.n = dice.t;
	dice.t = dice.s;
	dice.s = tmp;

	if (map[Y][X] == 0) {
		map[Y][X] = dice.b;
	}
	else {
		dice.b = map[Y][X];
		map[Y][X] = 0;
	}

	cout << dice.t << "\n";

}
void toS() {
	if (Y + 1 >= N)
		return;
	Y++;
	int tmp = dice.b;
	dice.b = dice.s;
	dice.s = dice.t;
	dice.t = dice.n;
	dice.n = tmp;

	if (map[Y][X] == 0) {
		map[Y][X] = dice.b;
	}
	else {
		dice.b = map[Y][X];
		map[Y][X] = 0;
	}

	cout << dice.t << "\n";

}


int main() {
	cin >> N >> M >> Y >> X >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int d = 0;
	
	while (K--) {
		cin >> d;
		////동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
		if (d == 1) {
			toE();
		}
		else if (d == 2) {
			toW();
		}
		else if (d == 3) {
			toN();
		}
		else {
			toS();
		}
		
	}
}