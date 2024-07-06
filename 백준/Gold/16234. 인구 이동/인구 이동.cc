#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int N, L, R;
int limit;

bool visit[51][51];
int map[51][51];
int sum;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
bool chk;
void bfs(int r,int c) {
	queue<pair<int, int>>q;
	vector<pair<int,int>>v;

	q.push({ r,c });
	v.push_back({ r,c });

	visit[r][c] = true;
	sum = map[r][c];
	while (!q.empty()) {

		
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int toY = curY + dy[i];
			int toX = curX + dx[i];

			if (toY < 0 || toY >= N || toX < 0 || toX >= N)
				continue;
			if (visit[toY][toX])
				continue;
			if (abs(map[curY][curX] - map[toY][toX]) >= L && abs(map[curY][curX] - map[toY][toX]) <= R) {
				sum += map[toY][toX];

				q.push({ toY,toX });
				v.push_back({ toY,toX });
				visit[toY][toX] = true;
			}
		}
	}

	// 각 칸수 갱신
	if (v.size() > 1) {
		chk = true;
		int n = sum / v.size();
		for (int i = 0; i < v.size(); i++) {
			int y = v[i].first;
			int x = v[i].second;
			map[y][x] = n;
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	
	while (true) {
		chk = false;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					bfs(i, j);
				}
			}
		}
		
		if (!chk)
			break;
		ans++;
	}
	
	// 경계를 연다 -> bfs , 한칸식 다 방문, 방문 여부 체크 ,누적합 가지고 있기 

	//갱신 한 적 없으면 종료 

	//좌표 
	//각 칸 개수 갱신 
	
	cout << ans;
	
}