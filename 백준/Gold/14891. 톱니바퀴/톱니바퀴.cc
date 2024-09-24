#include<iostream>
#include<string>
using namespace std;

//8:09

struct T{
	string b;//바퀴
	int idxR;//오른쪽 맞다아 있는 인덱스
	int idxL;//왼쪽 맞다아 있는 인덱스
};

T t[5];
string s;
int cnt;

int idx, dir;
pair<bool,int> r[5];
int tt = 0;
int score = 1;

void rotate(int idx, int dir) {// 1 : 시계 방향,  -1 : 반시계 방향
	
	if (dir == -1) {
		t[idx].idxR++;
		t[idx].idxL++;

		if (t[idx].idxL == 8)
			t[idx].idxL = 0;
		if (t[idx].idxR == 8)
			t[idx].idxR = 0;
	}
	else {
		t[idx].idxR--;
		t[idx].idxL--;

		if (t[idx].idxL == -1)
			t[idx].idxL = 7;
		if (t[idx].idxR == -1)
			t[idx].idxR = 7;
	}
}


//회전을 시킬 톱니바퀴와 방향을 정함
void find(int idx,int dir) {
	//오른쪽
	int dirT = dir;
	for (int i = idx + 1; i <= 4; i++) {
		
		if (t[i-1].b[t[i - 1].idxR] != t[i].b[t[i].idxL]) {
			//다른 극을 가지고 있으면 반대로 회전
			r[i] = { true,  dirT* -1 }; //-1이면 1로, 1이면 -1로
			dirT *= -1;
		}
		else
			break;
	}
	//왼쪽
	dirT = dir;
	for (int i = idx - 1; i >= 1 ; i--) {
		if (t[i].b[t[i].idxR] != t[i+1].b[t[i+1].idxL]) {
			//다른 극을 가지고 있으면 반대로 회전
			r[i] = { true, dirT * -1 };
			dirT *= -1;
		}
		else
			break;
	}

	//idx 회전
	rotate(idx, dir);
}


int main() {
	for (int i = 1; i <= 4; i++) {
		cin >> s;
		t[i] = { s,2,6 };
	}
	cin >> cnt;

	while (cnt--) {
		cin >> idx >> dir; // 1 : 시계 방향,  -1 : 반시계 방향
		for (int i = 1; i <= 4; i++)
			r[i] = { false,0 };

		find(idx, dir);
		for (int i = 1; i <= 4; i++) {
			if (r[i].first) {
				rotate(i, r[i].second);
			}
		}


	}
	int ans = 0;

	int tt = 0;
	int score = 1;
	for (int i = 1; i <= 4; i++) {
		tt = (t[i].idxR-2);
		
		if (tt < 0)
			tt = 8 + tt;
		
		if (t[i].b[tt] == '1') {
			
			ans += score;
		}
		score *= 2;
	}
	
	cout << ans;
}