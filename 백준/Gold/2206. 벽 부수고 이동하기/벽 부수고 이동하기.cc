#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n, m;
bool map[1001][1001];
bool visit[1001][1001];

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int ans =-1;

struct Pos
{
	int y;
	int x;
	bool isB;
	int d;
};

void bfs() {

	queue<Pos>q;// y,x, 벽부셨는지 여부
	q.push({0,0,false,1});
	visit[0][0] = true;

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		bool isB = q.front().isB;
		int d = q.front().d;
		//cout << curY << "  " << curX << endl;

		if (curY == n-1 && curX == m-1) {
			ans = d ;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
				continue;
			if (visit[ny][nx])
				continue;
			
			if (map[ny][nx] && isB) //이미 벽을 부신 적이 있다면 더 못부신다. 
				continue;
			if(map[ny][nx] && !isB)
				q.push({ ny,nx,true ,d+1});
			else
				q.push({ ny,nx,isB ,d + 1 });
			visit[ny][nx] = true;
		}
	}
}

void bfs2() {

	queue<Pos>q;// y,x, 벽부셨는지 여부
	q.push({ n-1,m-1,false,1 });
	visit[n-1][m-1] = true;

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		bool isB = q.front().isB;
		int d = q.front().d;
	//	cout << curY << "  " << curX << endl;

		if (curY == 0 && curX == 0) {
			if (ans == -1)
				ans = d;
			else
				ans = min(d, ans);
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
				continue;
			if (visit[ny][nx])
				continue;

			if (map[ny][nx] && isB) //이미 벽을 부신 적이 있다면 더 못부신다. 
				continue;
			if (map[ny][nx] && !isB)
				q.push({ ny,nx,true ,d + 1 });
			else
				q.push({ ny,nx,isB ,d + 1 });
			visit[ny][nx] = true;
		}
	}
}
int main() {
	cin >> n >> m;
	string s="";
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j]=s[j]-'0';
		}
	}
	
	

	bfs();
	memset(visit, 0, sizeof(visit));
	bfs2();
	cout << ans;

}