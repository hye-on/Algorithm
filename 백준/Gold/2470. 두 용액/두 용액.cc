#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int>num;
int main() {
	cin >> N;
	num.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int start = 0, end = N - 1, mid = 0;
	int v = 0, ans1 = 0, ans2 = 0;
	int min_n = 2000000001;
	
	while (start < end) {
		v = num[start] + num[end];
		mid = (start + end) / 2;
		
		if (abs(v) < abs(min_n)) {
			min_n = abs(v);
			ans1 = num[start];
			ans2 = num[end];
		}
		if (v > 0) {
			end--;
			
		}
		else {
			start++;
			
		}
		
	}
	

	cout << ans1 << " " << ans2;
	


}