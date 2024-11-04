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
	cin >> n;

	vector<int>histogram(n);
	

	for (int i = 0; i < n; i++) {
		cin >> histogram[i];
	
	}

	
	vector<int>arrLeft(n);
	stack<pair<int, int>>st; // 높이,idx
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top().first >= histogram[i]) {
			arrLeft[i]++;
			arrLeft[i] += arrLeft[st.top().second];
			st.pop();
			
		}
		

		st.push({ histogram[i],i });
	}

	vector<int>arrRight(n);
	st = s;
	for (int i = n-1; i >= 0; i--) {

		while (!st.empty() && st.top().first >= histogram[i]) {
			arrRight[i]++;
			arrRight[i] += arrRight[st.top().second];
			st.pop();
		}

		st.push({ histogram[i],i });
	}


	/*for (int i = 0; i < n; i++) {
		cout << arrLeft[i] << " " << arrRight[i] << endl;

	}*/

	int ans = 0, area = 0;
	for (int i = 0; i < n; i++) {
		if (histogram[i] == 0)
			continue;
		area = histogram[i] * (arrLeft[i] + arrRight[i] + 1);
		ans = max(area, ans);
	}
	cout << ans;
}
