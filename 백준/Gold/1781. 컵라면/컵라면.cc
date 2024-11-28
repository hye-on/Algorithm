#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//1:20 ~2:17
int n;

priority_queue<pair<int, int>>pq;//데드라인, 컵라면
int main() {
	cin >> n;
	int a = 0, b = 0;
	int ans = 0;
	int today = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		pq.push({ a,b });
		today = max(a, today);
		
	}

	priority_queue<int>frontDay;
	while (today>=1 ) {
		
		
		while (!pq.empty() &&today <= pq.top().first) {
			
			frontDay.push({ pq.top().second});
			pq.pop();
		}
		if (!frontDay.empty()) {
			ans += frontDay.top();
			
			frontDay.pop();
			
		}
		today--;
	}

	cout << ans;
}