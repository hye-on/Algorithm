#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 100000000
int r, c;
char map[1000][1000];
int fire[1000][1000];
int dist[1000][1000];
bool visit[1000][1000];

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int answer = -1;

void bfs_fire(int y_s,int x_s) {
	queue<pair<pair<int,int>,int>>q;
	q.push({ {y_s,x_s},0 });
	fire[y_s][x_s] = 0;

	while (!q.empty()) {
		
		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
				continue;
			if (d +1 >= fire[ny][nx] || map[ny][nx] == '#')//벽이거나 이미 방문 했으면
				continue;
			fire[ny][nx] = d + 1;
			q.push({ { ny,nx }, d + 1 });
		}

	}

}

void bfs_jh(int y_s, int x_s) {
	queue<pair<pair<int, int>, int>>q;
	q.push({ {y_s,x_s},0 });
	visit[y_s][x_s] = true;
	while (!q.empty()) {
		
		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second;
		//cout << y << "  " << x << endl;
		if (y == 0 || x == 0 || y == r-1 || x == c-1) {
			if (map[y][x] == '.' || map[y][x]=='J') {
				answer = d;
				break;
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
				continue;
			if (visit[ny][nx])
				continue;
			//cout << "d+1 "<<d+1<<"  "<<fire[ny][nx] << endl;
			if (d +1  >=fire[ny][nx] || map[ny][nx] == '#')//벽이거나 불이 먼저도달한 자리면
				continue;
			//cout << "방문 " << ny << "  " << nx << endl;
			//cout << d << "  " << fire[ny][nx] << endl;
			visit[ny][nx] = true;
			q.push({ { ny,nx }, d + 1 });
		}

	}

}

int main() {
	cin >> r >> c;
	int f_y=-1, f_x=-1, j_y=0, j_x=0;
	
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			fire[i][j] = MAX;
			if (map[i][j] == 'F') {
				f_y = i;
				f_x = j;
			}
			if (map[i][j] == 'J') {
				j_y = i;
				j_x = j;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(map[i][j]=='F')
				bfs_fire(i, j);
		}
	}
	bfs_jh(j_y, j_x);

	if (answer == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << answer+1;
	}
	/*cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << fire[i][j] << " ";
		}
		cout << endl;
	}*/
	
}