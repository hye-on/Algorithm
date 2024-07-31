#include<iostream>
#include<cmath>

using namespace std;

int N, L;
int num[201][201];
int ans;


void checkC(int y ) {
	
	int cnt = 0;
	for (int j = 0; j < N - 1; j++) {


		if (num[y][j] == num[y][j + 1])
			cnt++;
		else {

			if (abs(num[y][j] - num[y][j + 1]) > 1)
				return;

			if (num[y][j] < num[y][j+1]) { //올라감
				//cnt 체크
				
				if (cnt >= L - 1) {
					cnt = 0;
				}
				else
					return;
			}
			else { //내려감 새로운 길이 체크
				cnt = -1;
				for (int k = j + 1; k < j + L; k++) {
					if (num[y][k] != num[y][k + 1]) {
						return;
					}
				}
				j += L-1;
				

			}
		}

	}
//	cout << "y " << y << endl;
	ans++;
}
void checkR(int x) {

	int cnt = 0;
	for (int j = 0; j < N - 1; j++) {


		if (num[j][x] == num[j+1][x ])
			cnt++;
		else {

			if (abs(num[j][x] - num[j + 1][x]) > 1)
				return;

			if (num[j][x] < num[j + 1][x]) { //올라감
				//cnt 체크

				if (cnt >= L - 1) {
					cnt = 0;
				}
				else
					return;
			}
			else { //내려감 새로운 길이 체크
				cnt = -1;
				for (int k = j + 1; k < j + L; k++) {
					if (num[k][x] != num[k+1][x]) {
						return;
					}
				}
				j += L - 1;


			}
		}

	}
	//cout<<"x " << x << endl;
	ans++;
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num[i][j];
		}
	}

	//가로 
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt = 0;
		checkR(i);
		checkC(i);
	}
	cout << ans;
}