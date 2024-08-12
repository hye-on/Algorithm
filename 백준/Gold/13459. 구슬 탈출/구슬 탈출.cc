#include<iostream>
#include<queue>
using namespace std;

char map[11][11];
int N, M;
int ans = -1;
//3:10

char d[] = { 'R','L','T','B' };
bool isPos;

struct Pos {
	int ry;
	int rx;
	int by;
	int bx;
	int cnt;
};
queue<Pos>q; //R,B
bool findAns;
void move(char dir, Pos cur) {//R : 오른쪽 L: 왼쪽 
	Pos next;
	int cur_by = cur.by;
	int cur_bx = cur.bx;
	int cur_ry = cur.ry;
	int cur_rx = cur.rx;

	if (dir == 'R') {
		//BLUE X 증가
		while (cur_bx < M) {

			if (map[cur_by][cur_bx + 1] == '.') {
				cur_bx++;
			}
			else if (map[cur_by][cur_bx + 1] == '#') {
				break;
			}
			else if (map[cur_by][cur_bx + 1] == 'O') { //구멍에 빠지면 끝
				return;
			}
		}


		//RED X 증가
		while (cur_rx < M) {

			if (map[cur_ry][cur_rx + 1] == '.') {
				cur_rx++;

			}
			else if (map[cur_ry][cur_rx + 1] == '#') {
				break;
			}
			else if (map[cur_ry][cur_rx + 1] == 'O') {
				ans = cur.cnt;
				findAns = true;
				return;
			}
		}
		//만약 두 좌표가 같다면 더 뒤에 있었던 것 X--
		if (cur_bx == cur_rx && cur_by == cur_ry) {
			if (cur.bx < cur.rx)
				cur_bx--;
			else
				cur_rx--;
		}
		//새 좌표 큐에 넣기
		q.push({ cur_ry,cur_rx,cur_by,cur_bx,cur.cnt + 1 });
	}
	else if (dir == 'L') {
		//BLUE X 감소
		while (cur_bx > 1) {

			if (map[cur_by][cur_bx - 1] == '.') {
				cur_bx--;
			}
			else if (map[cur_by][cur_bx - 1] == '#') {
				break;
			}
			else if (map[cur_by][cur_bx - 1] == 'O') { //구멍에 빠지면 끝
				return;
			}
		}

		//RED X 감소
		while (cur_rx > 1) {
			if (map[cur_ry][cur_rx - 1] == '.') {
				cur_rx--;
			}
			else if (map[cur_ry][cur_rx - 1] == '#') {
				break;
			}
			else if (map[cur_ry][cur_rx - 1] == 'O') {
				ans = cur.cnt;
				findAns = true;
				return;
			}
		}
		//만약 두 좌표가 같다면 더 뒤에 있었던 것 X++
		if (cur_bx == cur_rx && cur_by == cur_ry) {
			if (cur.rx < cur.bx)
				cur_bx++;
			else
				cur_rx++;
		}
		//새 좌표 큐에 넣기
		q.push({ cur_ry,cur_rx,cur_by,cur_bx,cur.cnt + 1 });
	}
	else if (dir == 'T') {
		//BLUE Y 감소
		while (cur_by > 1) {
			if (map[cur_by - 1][cur_bx] == '.') {
				cur_by--;
			}
			else if (map[cur_by - 1][cur_bx] == '#') {
				break;
			}
			else if (map[cur_by - 1][cur_bx] == 'O') { //구멍에 빠지면 끝
				return;
			}
		}

		//RED Y 감소
		while (cur_ry > 1) {
			if (map[cur_ry - 1][cur_rx] == '.') {
				cur_ry--;
			}
			else if (map[cur_ry - 1][cur_rx] == '#') {
				break;
			}
			else if (map[cur_ry - 1][cur_rx] == 'O') {
				ans = cur.cnt;
				findAns = true;
				return;
			}
		}
		//만약 두 좌표가 같다면 더 뒤에 있었던 것 Y++
		if (cur_bx == cur_rx && cur_by == cur_ry) {
			if (cur.ry < cur.by)
				cur_by++;
			else
				cur_ry++;
		}
		//새 좌표 큐에 넣기
		q.push({ cur_ry,cur_rx,cur_by,cur_bx,cur.cnt + 1 });
	}
	else {
		//BLUE Y 증가
		while (cur_by < N) {
			if (map[cur_by + 1][cur_bx] == '.') {
				cur_by++;
			}
			else if (map[cur_by + 1][cur_bx] == '#') {
				break;
			}
			else if (map[cur_by + 1][cur_bx] == 'O') { //구멍에 빠지면 끝
				return;
			}
		}

		//RED Y 증가
		while (cur_by < N) {
			if (map[cur_ry + 1][cur_rx] == '.') {
				cur_ry++;
			}
			else if (map[cur_ry + 1][cur_rx] == '#') {
				break;
			}
			else if (map[cur_ry + 1][cur_rx] == 'O') {
				ans = cur.cnt;
				findAns = true;
				return;
			}
		}
		//만약 두 좌표가 같다면 더 뒤에 있었던 것 Y--
		if (cur_bx == cur_rx && cur_by == cur_ry) {
			if (cur.by < cur.ry)
				cur_by--;
			else
				cur_ry--;
		}
		//새 좌표 큐에 넣기
		q.push({ cur_ry,cur_rx,cur_by,cur_bx,cur.cnt + 1 });
	}
}

void bfs() {

	while (!q.empty()) {
		//각각 공을 4방향으로 굴려봄
		Pos cur = q.front();
		if (cur.cnt > 10)
			break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			move(d[i], cur);
			if (findAns)
				break;
		}
		if (findAns)
			break;
	}
}
int main() {

	cin >> N >> M;
	string tmp = "";
	Pos p;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= tmp.size(); j++) {
			map[i][j] = tmp[j - 1];
			if (map[i][j] == 'R') {
				p.rx = j;
				p.ry = i;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				p.bx = j;
				p.by = i;
				map[i][j] = '.';
			}

		}
	}
	p.cnt = 1;
	q.push(p);
	bfs();
	cout << findAns;
}