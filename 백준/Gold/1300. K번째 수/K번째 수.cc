#include<iostream>

using namespace std;

long long n, k, ans;
int main() {
	cin >> n >> k;

	long long start = 1, end = n * n,mid=0;
	int t = 0;
	long long ans = 0;
	while (start<= end) {
		mid = (start + end) / 2;
	
		//mid보다 작은 것의 개수를 구함
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			t = mid / i > n ? n : mid / i;
			sum += t;
		}
		
		if (sum < k) {
			start = mid + 1;
			
		}
		else {
			ans = mid;
			end = mid - 1;
			
		}
		
	}

	cout << ans;
}