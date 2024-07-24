#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
deque<int>dq;
int n,f,b;
bool isR;
int main() {
	cin >> n>>f>>b;
	if (f + b-1 > n) {
		cout << -1;
		return 0;
	}
	int tmp = 0;
	
	//1. 1~f까지 입력
	for (int i = 1; i < f; i++)
		dq.push_back(i);
	//최댓값 입력
	dq.push_back(max(f, b));
	//2. 끝에서부터 추가
	for (int i = b-1; i >= 1; i--)
		dq.push_back(i);
	//3. 남는 개수만큼 1 앞에 붙히기
	int cnt = n - (f + (b - 1));
	
	while (cnt>0 &&cnt--) {
		
		dq.insert(dq.begin()+1, 1);
	}


	for (int i = 0; i < n; i++) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}

}