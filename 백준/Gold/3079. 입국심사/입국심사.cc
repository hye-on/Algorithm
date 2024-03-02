#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long N, M;
vector<long long>num;
int main() {
	cin >> N >> M;
	num.resize(N);
	long long max_n = 0;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		max_n = max(num[i], max_n);
	}

	unsigned long long start = 0, end = max_n*M, mid = 0, sum = 0,ans;
	while (start <= end) {
		mid = (start + end) / 2;
		sum = 0;
		
		for (int i = 0; i < N; i++) {
			sum += mid / num[i];
		}

		if (sum >= M) {
			end = mid - 1;
			ans =  mid;
		}
		else {
			start = mid + 1;
		}

	}

	cout << ans;

}