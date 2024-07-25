#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n,tmp;
priority_queue<int>q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			q.push(-tmp);
		}
		while (q.size() > n)
			q.pop();

	}

	
	cout << -q.top();
}