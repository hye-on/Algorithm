#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long m;
long long ans;
int n;
vector<long long> dis;
vector<long long>node;
int main() {
	cin >> n;
	dis.resize(n - 1);
	node.resize(n);
	for (int i = 0; i < n-1; i++) {
		cin >> dis[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> node[i];
	}
	m = node[0];
	for (int i = 1; i < n; i++) {
		ans += dis[i - 1] * m;
		m = min(node[i], m);
	}
	cout << ans;
}