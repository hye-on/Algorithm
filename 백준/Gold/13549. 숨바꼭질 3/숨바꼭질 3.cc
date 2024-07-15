#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[200000] = {0};
queue<pair<int, int>> q;

int bfs() {
	while(!q.empty()) {
		int value = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(value == k) return cnt;
		
		int teleport = 2;
		while(value*teleport < 200000 && visited[value*teleport] == 0) {
			q.push(make_pair(value*teleport, cnt));
			visited[value*teleport] = 1;
			teleport *= 2;
		}
		
		if(visited[value-1] == 0 && value-1 >= 0) {
			q.push(make_pair(value-1, cnt+1));
			visited[value-1] = 1;
		}
		
		if(visited[value+1] == 0 && value < 100000) {
			q.push(make_pair(value+1, cnt+1));
			visited[value+1] = 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	
	q.push(make_pair(n, 0));
	visited[n] = 1;
	
	int res = (n==k) ? 0 : bfs();
	
	cout << res;
	return 0;
}