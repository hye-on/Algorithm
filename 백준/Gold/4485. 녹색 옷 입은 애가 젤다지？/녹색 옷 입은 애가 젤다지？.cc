#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n;
vector<vector<int>>map(125, vector<int>(125, -1));
vector<vector<int>>dist(125, vector<int>(125,0));
int ans;
struct Pos {
	int y;
	int x;

	bool operator<(const Pos& other) const {
		if (y < other.y)
			return true;
		else
			return false;
	}
};

void dijikstra() {
	priority_queue<pair<int,Pos>>q;
	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };
	q.push({ -map[0][0], {0,0 } });
	
	dist[0][0] = map[0][0];
	while (!q.empty()) {

		int curY = q.top().second.y;
		int curX = q.top().second.x;

		int curCost = -q.top().first;
		
		q.pop();
	
		if (curCost > dist[curY][curX])
			continue;
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			//현재 비용 + 다음 노드 거치는 비용
			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			int c = curCost + map[nextY][nextX];
			
			
			if (c < dist[nextY][nextX]) {
				dist[nextY][nextX] =c;
				q.push({ -c,{nextY,nextX} });

			}
				
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int idx = 1;
	while (true) {

		cin >> n;

		fill(map.begin(), map.end(), vector<int>(125, 0));
		fill(dist.begin(), dist.end(), vector<int>(125, 10000000));
		
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		dijikstra();
		cout << "Problem "<<idx<<": " << dist[n - 1][n - 1] << "\n";
		idx++;

	}
}