#include<iostream>

using namespace std;

//union-parent 풀이

//findParent
int n;
int m;
int parent[201];
int path[1000];
int tmp;

int findParent(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = findParent(parent[a]);
}

//unionParent : 작은 것으로 부모 노드를 통일
void unionParent(int a,int b) {
	a = findParent(a);
	b = findParent(b);
	
	if (a > b) parent[a] = b;
	else parent[b] = a;

}



int main() {
	cin >> n;
	cin >> m;
	//parent 초기화
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (tmp == 1)
				unionParent(i, j);

		}
	}
	bool ans = true;
	
	for (int i = 0; i < m; i++) {
		cin >> path[i];
		if (i > 0) {
			if (findParent(path[i - 1]) != findParent(path[i])) {
				ans = false;
				break;
			}
		}
	}

	if (ans)
		cout << "YES";
	else
		cout << "NO";
	

}
