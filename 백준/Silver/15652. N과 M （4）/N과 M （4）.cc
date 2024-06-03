#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int>visit;
vector<int>num;
void backtracking(int idx,int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= N; i++) {
		
		num[depth] = i;
		backtracking(i , depth + 1);
	}

}
int main() {
	cin >> N >> M;
	visit.resize(N + 1);
	num.resize(N+1);
	backtracking(1, 0);
}