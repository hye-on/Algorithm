#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int N, M;
const int MAXN = 100000;	//�ʱ�ȭ ���� ��
int arr[MAXN + 1];
vector<int> min_tree, max_tree;

void init(int node, int start, int end) {
	if (start == end) {//�� ������ ����.
		min_tree[node] = max_tree[node] = arr[start];
		return;
	}
	else {
		//0~11   
		init(node * 2, start, (start + end) / 2);// 0~5
		init(node * 2 + 1, (start + end) / 2 + 1, end);// 6~11
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);//�� �ڽ� ����� �ּҰ��� �� ���� ��
		//min( 0~5, 6~11)
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
		return;
	}
}
//0~11    0~3
pair<int, int> findMinMAx(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {     //  start   left  right end  ->    start   end    left  right  or    left  right  start   end 
		return make_pair(INT32_MAX, 0);	//������ �Ѿ�� �ּڰ�,�ִ� x -> �ִ�,�ּڰ� ��ȯ
	}
	else if (left <= start && end <= right) {//���� ���̸�   left  start end right  0  0 2  3 ||  0 3 3 3
		return make_pair(min_tree[node], max_tree[node]); //�ּڰ��� �ִ� ��ȯ
	}
	else {//�Ѵ� �ƴ϶�� ���� ������ ���� �ִ� ��. ��ͷ� ����
		pair<int, int> l, r;// 0  11 ->  0~5  , 6~11    ->   0~2,3~5 ->3~4, 5->3,4
		l = findMinMAx(node * 2, start, (start + end) / 2, left, right);//2�� ���ϸ� ���� �ڽ� ���
		r = findMinMAx(node * 2 + 1, (start + end) / 2 + 1, end, left, right);//2���ϰ� 1���ϸ� ������ �ڽ� ���
		return make_pair(min(l.first, r.first), max(l.second, r.second));
	}
}

int main() {
	
	cin >> N >> M;
	int h = (int)ceil(log2(N)); // N=12     ceil(3.xxx)  = 4  , h=4
	//�������� ������ N���� �� N���� ���� ����� N�� �������� ���� �ڿ�
	//�װ��� 2����� �̸� �迭�� ũ�⸦ ����� ���ƾ��Ѵ�.
	min_tree = vector<int>(1 << (h + 1));// h+1  (2�� �������)
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