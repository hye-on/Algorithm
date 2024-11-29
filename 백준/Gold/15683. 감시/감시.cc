#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//1:15 ~2:12

//n이 작아서 완탐

int n, m;
int map[8][8];
int cctvCnt;
int cctvArea;

//방향을 비트마스크?

int cnt[] = { 0,4,2,4,4,1 }; // 2번은 2개 케이스 , 5번은 1개 케이스
vector<pair<int, int>>cctv; // 
string choice[9];

vector<vector<string>> dir = {
	{},
	{"1000", "0100", "0010", "0001"}, //1
	{"1100","0011"}, //2
	{"1001","1010","0101","0110"}, //3  상우, 상좌, 하우, 하좌
	{"1110","1101","1011","0111"}, //4
	{"1111"}  //5
};
// 0101 상하좌우 각 표시 
int dy[] = { -1,1,0,0 }; //상하좌우
int dx[] = { 0,0,-1,1 };

bool visit[8][8];

int cntOneDir(int dir, int idx) { //idx번째 cctv를 dir방향으로 검사
	int y = cctv[idx].first;
	int x = cctv[idx].second;

	int cnt = 0;
	while (true) {
		y += dy[dir];
		x += dx[dir];
		if (y >= n || y < 0 || x >= m || x < 0)
			break;
		if (map[y][x] == 6)
			break;
		if (!visit[y][x]) {
			//방문한 적 없고 빈칸이면 체크. 다른 cctv일 수도 있어서
			if(map[y][x]==0)
				cnt++;
			visit[y][x] = true;
		}
	}
	return cnt;
}
void cntArea() {
	//각 cctv마다 
	int sum = 0;
	
	for (int i = 0; i < cctvCnt; i++) {
		//4방향으로 검사
		for (int j = 0; j < 4; j++) {
			//그 방향으로 검사 가능하면
			if(choice[i][j]=='1')
				sum += cntOneDir(j, i);
		}
	}
	
	cctvArea = max(cctvArea, sum);
}

void backtraking(int depth) {
	if (depth == cctvCnt) {
		cntArea();
		memset(visit, false, sizeof(visit));
		return;
	}
	int cctvNum = map[cctv[depth].first][cctv[depth].second];
	int cctvCase = cnt[cctvNum];
	
	for (int i = 0; i < cctvCase; i++) {
		choice[depth] = dir[cctvNum][i];
		backtraking(depth + 1);
	}
}

int main() {


	cin >> n >> m;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctv.push_back({ i, j });
				cctvCnt++;		
			}
			if (map[i][j] == 0)
				answer++;
		}
	}

	backtraking(0);
	answer -= cctvArea;
	cout << answer;
	
}