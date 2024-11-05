#include <iostream>

using namespace std;

int n;
int pre[1001];
int in[1001];


void postOrder(int start, int end, int rootIdx) {
	
	for (int i = start; i < end; i++) {
		if (in[i] == pre[rootIdx]) {
			postOrder(start, i,rootIdx+1 ); //{start,end(in에서 범위 ) - pre에서의 인덱스}
			postOrder(i+1,end, rootIdx + 1 + i - start); //이부분 주의, 오른쪽 루트 인덱스 찾는 부분
			cout << pre[rootIdx] << ' ';
			break;
		}
	}
	
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> pre[i];

		for (int i = 0; i < n; i++)
			cin >> in[i];

		postOrder(0,n,0);
		cout << "\n";
	}
	

}
