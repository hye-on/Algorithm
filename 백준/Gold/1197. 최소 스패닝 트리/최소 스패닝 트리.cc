#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[10001];
vector<pair<int,pair<int, int>>>link;
int cnt;
int cost, nodeA, nodeB;
int ans;

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[b] = a;
}

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		link.push_back({ c,{a,b} });
	}
	sort(link.begin(), link.end());

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	
	for (int i = 0; i < link.size(); i++) {
		cost = link[i].first;
		nodeA = link[i].second.first;
		nodeB = link[i].second.second;

		if (findParent(nodeA) == findParent(nodeB)) continue;

		unionParent(nodeA, nodeB);
		ans += cost;


		if (++cnt == v - 1)break;
	}
	cout << ans;
}