#include<iostream>
#include<algorithm>

using namespace std;

int n;
int high[51];
int cnt;
int ans;
double tmp;
//기울기
double cal(int curIdx, int idx) {
	return (double)(high[idx] - high[curIdx]) / (double)(idx - curIdx);
}
int main(){
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> high[i];
	for (int i = 0; i < n; i++) {
		cnt = 0;
		tmp = 1000000002;
		//기울기가 더 작아야 가능
		if (i != 0) {
			
			for (int j = i - 1; j >= 0; j--) {
				if (cal(i,j) >= tmp)
					continue;
				else {
					cnt++;

					tmp = cal(i, j);

				}

			}
		}
		tmp = -1000000002;
		
		//기울기가 더 커야 가능
		if (i != n - 1) {
			
			for (int j = i + 1; j < n; j++) {
				if (cal(i, j) <= tmp) {


					continue;
				}	
				else {
					cnt++;
					tmp = cal(i, j);
				}
			}
		}
		//cout << i << "  " << cnt << endl;
		ans = max(cnt, ans);
	}

	cout << ans;
}