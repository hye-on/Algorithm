#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

// 양방향으로 검사
// 스택은 오름차순으로 쌓기

// 들어오는 애보다 스택의 top이 더 크면 pop
// 같으면 arr 값 += 

int n;
stack<pair<int, int>>s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<int>histogram(n+1);
	
	for (int i = 0; i < n; i++) {
		cin >> histogram[i];
	
	}

	histogram[n] = - 1;
		
	stack<pair<int, int>>st; // 높이,idx
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int minPos = i;
		while (!st.empty() && st.top().first >= histogram[i]) {
			auto [h, pos] = st.top();
			ans = max(h * (i - pos), ans);
			minPos = min(i, st.top().second); // 2, 1일때 2를 pop함 하지만 1의 높이로 0번째 인덱스까지 그릴 수 있음
			st.pop();
		}

		st.push({ histogram[i],minPos });
	}
	cout << ans;
}
