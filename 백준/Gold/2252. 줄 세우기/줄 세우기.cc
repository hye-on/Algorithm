#include<iostream>
#include<vector>
#include<queue>

#define MAX 32001
using namespace std;

int N, M;
int inDegree[MAX];
vector<int>a[MAX];
int result[MAX];

int c, d;

void topologySort() {
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < a[x].size(); j++) {
			if (--inDegree[a[x][j]] == 0)
				q.push(a[x][j]);
		}
	}
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> c >> d;
		a[c].push_back(d);
		inDegree[d]++;
	}
	topologySort();
	for (int i = 0; i < N; i++)
		cout << result[i] << " ";

}