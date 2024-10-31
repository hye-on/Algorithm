#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//02:39 ~ 3:13
//크루스칼
int n, m;
priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
vector<int>parent;

int findParent(int a) {
	if (parent[a] == a)
		return a;

	return parent[a] = findParent(parent[a]);
}

void unionParent(int a,int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> m >> n; //집의 수, 길의수
		if (m == 0 && n == 0) {
			break;
		}

		parent.resize(m);
		for (int i = 0; i < m; i++)
			parent[i] = i;

		// 크루스칼을 위해 우선순위큐에 담아줌
		int ans = 0;
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;


			pq.push({ z,{x,y} });
			ans += z;
		}


		//union-find로 최소비용으로 합집합 만들기
		while (!pq.empty()) {

			int v = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (findParent(x) != findParent(y)) {
				unionParent(x, y);
				ans -= v;
			}
		}

		cout << ans << "\n";
	}
}