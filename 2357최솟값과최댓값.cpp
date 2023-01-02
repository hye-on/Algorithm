#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int N, M;
const int MAXN = 100000;	//초기화 해줄 값
int arr[MAXN + 1];
vector<int> min_tree, max_tree;

void init(int node, int start, int end) {
	if (start == end) {//더 나눌수 없다.
		min_tree[node] = max_tree[node] = arr[start];
		return;
	}
	else {
		//0~11   
		init(node * 2, start, (start + end) / 2);// 0~5
		init(node * 2 + 1, (start + end) / 2 + 1, end);// 6~11
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);//두 자식 노드의 최소값중 더 작은 것
		//min( 0~5, 6~11)
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
		return;
	}
}
//0~11    0~3
pair<int, int> findMinMAx(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {     //  start   left  right end  ->    start   end    left  right  or    left  right  start   end 
		return make_pair(INT32_MAX, 0);	//범위를 넘어가면 최솟값,최댓값 x -> 최댓값,최솟값 반환
	}
	else if (left <= start && end <= right) {//범위 안이면   left  start end right  0  0 2  3 ||  0 3 3 3
		return make_pair(min_tree[node], max_tree[node]); //최솟값과 최댓값 반환
	}
	else {//둘다 아니라는 것은 범위에 걸쳐 있는 것. 재귀로 분할
		pair<int, int> l, r;// 0  11 ->  0~5  , 6~11    ->   0~2,3~5 ->3~4, 5->3,4
		l = findMinMAx(node * 2, start, (start + end) / 2, left, right);//2를 곱하면 왼쪽 자식 노드
		r = findMinMAx(node * 2 + 1, (start + end) / 2 + 1, end, left, right);//2곱하고 1더하면 오른쪽 자식 노드
		return make_pair(min(l.first, r.first), max(l.second, r.second));
	}
}

int main() {
	
	cin >> N >> M;
	int h = (int)ceil(log2(N)); // N=12     ceil(3.xxx)  = 4  , h=4
	//데이터의 개수가 N개일 때 N보다 가장 가까운 N의 제곱수를 구한 뒤에
	//그것의 2배까지 미리 배열의 크기를 만들어 놓아야한다.
	min_tree = vector<int>(1 << (h + 1));// h+1  (2배 만들려고)
	max_tree = vector<int>(1 << (h + 1));

	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	init(1, 1, N);
	int left, right;
	pair<int, int> result;
	while (M--) {
		cin >> left >> right;
		result = findMinMAx(1, 1, N, left, right);
		cout << result.first << " " << result.second << endl;
	}
	return 0;
}


//#include<iostream>
//
//using namespace std;
//
//int N, M;
//int a, b;
//int num[100000];
//
//int main()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		cin >> num[i];
//
//	while (M--) {
//		cin >> a >> b;
//
//	}
//}