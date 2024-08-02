#include<iostream>
#include<queue>

using namespace std;
int n, k;

int map[13][13]; //0흰, 1 빨, 2 파
int cnt[13][13];
pair<int, int>pos[13][13][10]; //말 번호, 방향 - 오, 왼, 위, 아래
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq; //말 번호, 위치 {y,x}

//오 , 왼 , 위 , 아래
int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,-1,1};

int blue(int y, int x, int dir) {
	
	//방향만 바꿈 
	if (dir <= 2)
		dir = 3 - dir;
	else
		dir = 7 - dir;
	pos[y][x][0].second = dir;
	return dir;
}

void move(int node, int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	//파랑
	if (ny > n || ny <= 0 || nx > n || nx <= 0 || map[ny][nx] == 2)
	{
		dir = blue(y, x, dir);
		ny = y + dy[dir];
		nx = x + dx[dir];
		//또 파랑이나 벽이면 방향만 바꾼다.
		if (ny > n || ny <= 0 || nx > n || nx <= 0 || map[ny][nx] == 2)
			return;
	}
	//흰
	if (map[ny][nx] == 0) {
		int inputIdx = cnt[ny][nx];
		int endIdx = cnt[y][x];
		cnt[ny][nx] += cnt[y][x];
		cnt[y][x] = 0;
		int i = 0;
		while (i < endIdx) {
			pos[ny][nx][inputIdx++] = pos[y][x][i];		
			i++;
		}
	}
	else if (map[ny][nx] == 1) {
		int inputIdx = cnt[ny][nx];
		int endIdx = 0;
		int i = cnt[y][x]-1 ; // 3개 있으면 2,1,0
		cnt[ny][nx] += cnt[y][x];
		cnt[y][x] = 0;
		while (i >= endIdx) {
			pos[ny][nx][inputIdx++] = pos[y][x][i];
			i--;
		}
		if (pos[ny][nx][0].first > node) {// 반전 시켰는데 바닥에 있는 애가 더 크다면 얘도 움직여줘야 함
			pq.push({ pos[ny][nx][0].first , {ny,nx} });
		}
	}

	
}

bool cntN() {
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt[i][j] >= 4) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int r, c, d;
	for (int i = 1; i <= k; i++) {
		cin >> r >> c >> d;
		pq.push({ i,{r,c} });
		pos[r][c][0] = { i,d };
		cnt[r][c] = 1;
	}

	int turn = 0;
	while (turn <= 1000) {
		if (cntN())
			break;
		turn++;
		

		// pq가 빌 때까지 하나 씩 움직임
		while (!pq.empty()) {
			
			int curY = pq.top().second.first;
			int curX = pq.top().second.second;
			int curN = pq.top().first;
			int d = pos[curY][curX][0].second;
			pq.pop();

			move(curN, curY, curX ,d );
	

		}

		//pq를 채워줌
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt[i][j] > 0) {
					//말 번호, y, x
					
					pq.push({ pos[i][j][0].first,{i,j} });
				}
			}
		}

	}
	
	if (turn > 1000)
		cout << -1;
	else
		cout << turn;

}