#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int k;
int w, h;
int map[201][201];

bool visit[201][201][31];
int answer = 1000000000;

struct node
{
	int y;
	int x;
	int k;
	int d;
};

void bfs() {
	queue<node>q;
	q.push({ 0,0,k,0 });
	int hx[]={ 2, 1, 2, 1, -2, -1, -2, -1 };
	int	hy[] = { -1, - 2, 1, 2, 1, 2 ,- 1, -2 };

	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };

	while (!q.empty()) {

		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_k = q.front().k;
		int cur_d = q.front().d;
		visit[cur_y][cur_x][0] = true;
		q.pop();
		if (cur_y == h - 1 && cur_x == w - 1) {
			
			answer = min(answer, cur_d);
		}

		for (int i = 0; i < 4; i++) {
			int y = cur_y + dy[i];
			int x = cur_x + dx[i];
			if (y < 0 || y >= h || x < 0 || x >= w)
				continue;
			if (!visit[y][x][cur_k] && !map[y][x]) {
				visit[y][x][cur_k] = true;
				q.push({ y,x,cur_k,cur_d+1 });
			}
		}
		if (cur_k > 0) {
			for (int i = 0; i < 8; i++) {
				int y = cur_y + hy[i];
				int x = cur_x + hx[i];
				//cout << y << "  " << x << endl;

				if (y < 0 || y >= h || x < 0 || x >= w)
					continue;
				if (!visit[y][x][cur_k-1] && !map[y][x] ) {
					visit[y][x][cur_k-1] = true;
					q.push({ y,x,cur_k - 1,cur_d + 1 });
				}
			}
		}
	}
}
int main() {
	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	bfs();
	if (answer == 1000000000)
		answer = -1;
	cout << answer;
	
}