#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//07:44~7:54
// 08:51

int n, m;
int main() {
	cin >> n >> m;
	
	vector<int>playM(m + 1); //1~m

	for (int i = 1; i <= m; i++) {
		cin >> playM[i];
	}
	if (n <= m) {
		cout << n << endl;
		return 0;
	}
	long long start = 0, end = 60000000001, mid = 0;
	long long ansIdx = 0;
	
	//n보다 커야함 
	while (start + 1 < end) {
		
		//mid 시간 
		mid = (start + end) / 2;
	
		long long sum = m;
		for (int i = 1; i <= m; i++) {
			
			sum += mid / playM[i]; //놀이기구당 탈 수 있는 인원
		}
	
		if (sum >= n) {
			end = mid;
			ansIdx = mid;
		
		}
		else {
			start = mid;
			
		}
	}
		
	long long sumT = m;
	for (int i = 1; i <= m; i++) {// 9초에 타러간 아이들 숫자
		sumT += (ansIdx - 1) / playM[i];
	}

	for (int i = 1; i <= m; i++) { // time초에 타러가는 아이들 숫자 갱신
		if (ansIdx % playM[i] == 0)
			sumT++;
		if (sumT == n) {//마지막 아이가 타러 들어가는 놀이기구 번호 
			cout << i << "\n"; break;
		}
	}

	

}