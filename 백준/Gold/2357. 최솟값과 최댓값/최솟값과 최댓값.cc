#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000000000
#define MIN 1
int n, m;

//1:30
//세그먼트 트리
vector<int>v;
vector<pair<int,int>>tree; //최소, 최대 

pair<int,int> init(int start, int end, int node) {
	if (start == end)
		return tree[node] = { v[start], v[start] };

	int mid = (start + end) / 2;

	init(start, mid, node * 2);
	init(mid+1, end, node * 2 + 1);
	tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
	tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
	return tree[node];
}

pair<int, int>findMinMax(int start,int end, int node, int left, int right) {
	if (right < start || end < left)
		return { MAX + 1,MIN - 1 };
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	pair<int,int> lt = findMinMax(start, mid, node * 2, left, right);
	pair<int,int> rt = findMinMax(mid + 1, end, node * 2 + 1, left, right);
	return { min(lt.first,rt.first),max(lt.second,rt.second) };
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	cin >> n >> m;

	v.resize(n);
	tree.resize(n * 4);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	init(0,n-1,1);
	int start = 0, end = 0;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		//구간 최소 최대 찾기
		pair<int, int > ans = findMinMax(0, n-1, 1, start-1, end-1);
		cout << ans.first << " " << ans.second << "\n";
	}
}