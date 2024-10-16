#include<iostream>
#include<algorithm>

using namespace std;
int L, K, C;

int loc[10002];
int w[10001];
#define INF 987654321;
int main() {
	cin >> L >> K >> C;
	int tmp = 0;
	w[0] = 0;
	for (int i = 1; i <= K; i++) {
		cin >> w[i];
	}
	w[K + 1] = L;
	sort(w, w + K + 1);

	for (int i = 0; i <=K; i++) {
		
		loc[i] = w[i+1] - w[i];
	}
	

	int start = 0, end = L, mid = 0; //mid 는 최소 길이
	int p = 0, idx = L, ans1 = L, ans2 = L;
	//첫 번째 수는 가장 긴 조각의 길이이고, 두 번째 수는 그 때 처음 자르는 위치
	while (start <= end) {
		mid = (start + end) / 2;
		int cnt = 0;
		int sum = 0;
		for (int i = K+1; i >= 0; i--) {
			
			if (loc[i] > mid) {
				cnt = INF;
				
				break;
			}

			//모든 조각이 mid보다 작아야 함
			// 이번꺼까지 더했을 때 mid초과이면
			if (sum + loc[i] > mid) {
				cnt++;
				idx = i;
				sum = 0;
				
			}
			sum += loc[i];
		}
	
		
		if (cnt > C) {
			start = mid + 1;			
		}
		else {
			
			end = mid-1;
			ans2 = (cnt == C) ? w[idx+1] : w[1];
			ans1 = mid;			
				
		}

		
	}
	
	cout << ans1 << " " << ans2 << endl;
	
}
