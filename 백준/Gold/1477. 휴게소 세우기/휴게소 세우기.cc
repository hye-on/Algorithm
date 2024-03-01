#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int>road;
	
int N, M, L;
int main() {

	cin >> N >> M >> L;
	road.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> road[i];
	}
	road.push_back(0);
	road.push_back(L);

	sort(road.begin(), road.end());

	int start = 1, end = L-1;
	int mid = 0;
	int distance = 0;
	int cnt = 0;
	int ans = L;
	while (start <= end) { // = or x
		mid = (start + end) / 2;
		cnt = 0;
		for (int i = 0; i < N + 1; i++) {
			distance = road[i + 1] - road[i];
			cnt += distance/mid;
			if (distance % mid == 0) {
				cnt--;
			}
		}

		if (cnt > M)
		{
			start = mid + 1;
		}
		else {
			end = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans;
}