#include<iostream>

using namespace std;


int n, m;
int A[1000000];
int B[1000000];
int idxA, idxB,idxE;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}	
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	idxE = n + m ;
	while (true) {
		if (idxA == n) {
			while (idxB != m) {
				cout << B[idxB] << " ";
				idxB++;
			}
			break;
		}
		if (idxB == m) {
			while (idxA != n) {
				cout << A[idxA] << " ";
				idxA++;
			}
			break;
		}
		if (A[idxA] < B[idxB]) {
			cout << A[idxA] << " ";
			idxA++;
		}
		else {
			cout << B[idxB] << " ";
			idxB++;

		}
	}
}