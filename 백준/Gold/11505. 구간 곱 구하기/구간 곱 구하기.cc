#include<iostream>
#include<vector>

using namespace std;


//4:01
int N, M, K;
typedef long long ll;

//세그먼트 트리 - 구현 기억 안남
vector<ll>v;
vector<ll>tree;
int MOD = 1000000007;


ll init(int start, int end, int node) { //v의 시작 ~끝, node: tree의 노드를 가르킴
	if (start == end)
		return tree[node] = v[start];
	int mid = (start + end) / 2;
	//재귀적으로 두 구간으로 나누고 그 곱을 나로  함
	return tree[node] = (init(start, mid, node * 2) * init(mid+1, end, node * 2 + 1))% MOD; // {0, 10, 1} -> {0, 5, 2} + {6,10,3} 
}

void  update(int start, int end, int node, int idx, int dif, int dif2) { // double로 하면 손실 값 생길것 같다. 
	//범위 밖
	if (idx < start || end < idx) 
		return;

	if (start == end) {
		tree[node] = dif2;
		v[idx] = dif2;
		return;
	}

	//내려가면서 계속 갱신
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif, dif2);
	update(mid + 1, end, node * 2 + 1, idx, dif, dif2);

	tree[node] = ((tree[node * 2] % MOD )* (tree[node * 2 + 1] % MOD)) % MOD;

}

//구간 곱 구하기
ll multi(int start, int end, int node, int left, int right) {
	//범위 안에 없음
	if (right < start || end < left)
		return 1;

	//범위 안
	if (left <= start && end <= right)
		return tree[node];

	//범위 걸치면
	int mid = (start + end) / 2;

	return (multi(start, mid, node * 2, left, right))% MOD * (multi(mid + 1, end, node * 2 + 1, left, right)%MOD)% MOD;
	
}
int main() {

	cin >> N >> M >> K;

	v.resize(N + 1);
	tree.resize(4 * N); // (N보다 조금 큰 값 (제곱수) )*2< N * 4

	for (int i = 0; i < N; i++)
		cin >> v[i];

	int cmd = 0, b = 0, c = 0;

	init(0, N - 1, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> cmd >> b >> c;

		if (cmd == 1) {
			
			update(0, N - 1, 1, b - 1, v[b - 1], c);
			
			
		}
		else
			cout << multi(0, N - 1, 1, b - 1, c - 1) << "\n";
	}
	
}