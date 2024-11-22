#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>


using namespace std;

int t, r, c;
string map[100];
bool visit[100][100];
string key;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int ans;
queue<pair<int, int>>abcq[26];

void removeDoor(char key, queue<pair<int, int>>&q) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (tolower(map[i][j]) == key) {
				map[i][j] = '.';
				if(visit[i][j])
					q.push({ i, j });
				
			}
		}
	}
}

void bfs(queue<pair<int, int>>&q) {
	queue<pair<int, int>>tq;
	while (!q.empty()) {
		
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
	
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			
			if (ny >= r || ny < 0 || nx >= c || nx < 0 || visit[ny][nx])
				continue;
		

			if (map[ny][nx] == '.') {
				q.push({ ny, nx });
				visit[ny][nx] = true;
			}
			else if (map[ny][nx] <= 'Z' && map[ny][nx] >= 'A') {
				visit[ny][nx] = true;
			}
			else if (map[ny][nx] == '$') {

				ans++;
				q.push({ ny, nx });
				visit[ny][nx] = true;
			}
			else if (map[ny][nx] <= 'z' && map[ny][nx] >= 'a') {
				q.push({ ny, nx });		
				removeDoor(map[ny][nx],q);
				visit[ny][nx] = true;
			}


		}
	}
}


int main() {
	cin >> t;
	while (t--) {
		ans = 0;
		memset(visit, false, sizeof(visit));


		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			cin >> map[i];
			
		}
		cin >> key;
		queue<pair<int, int>>tempQ;
		if (key != "0") {
			for (int i = 0; i < key.size(); i++) {
				removeDoor(key[i],tempQ);		
			}
		}
		queue<pair<int, int>>q;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
					
					//들어갈 수 있는 입구를 q에 넣어준다.
					if ('a' <= map[i][j] && map[i][j] <= 'z') {
						removeDoor(map[i][j], tempQ);
						visit[i][j] = true;
						q.push({ i,j });
					}
					if ('A' <= map[i][j] && map[i][j] <= 'Z') {
						visit[i][j] = true;
					}
					else if (map[i][j] == '.') {
						visit[i][j] = true;
						q.push({ i,j });
					}
					else if (map[i][j] == '$') {
						visit[i][j] = true;
						q.push({ i,j });
						ans++;

					}
					
				}
			}
			

		}

		while (!tempQ.empty()) {

			int y = tempQ.front().first;
			int x = tempQ.front().second;

			tempQ.pop();

			if(y == 0 || y== r-1 || x==0 || x==c-1){
				visit[y][x] = true;
				q.push({ y,x });
			}
		}

		if (q.size() == 0)
			cout << '0' << "\n";
		else {
			bfs(q);
			cout<< ans << "\n";
		}
		
	}
}