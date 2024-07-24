#include<iostream>
#include<queue>

using namespace std;
deque<int>dq;
int n, f, b;
bool isR;
int main() {
	cin >> n >> f >> b;
	if (f + b - 1 > n) {
		cout << -1;
		return 0;
	}
	int tmp = 0;
	if (b > f) {//출력할 때 뒤부터 출력
		isR = true;
		tmp = f;
		f = b;
		b = tmp;
	}
	//1. 1~f까지 입력
	for (int i = f; i > 0; i--)
		dq.push_front(i);
	//2. 끝에서부터 추가
	for (int i = b - 1; i >= 1; i--)
		dq.push_back(i);
	//3. 남는 개수만큼 1 앞에 붙히기
	int cnt = n - (f + (b - 1));


	while (cnt > 0 && cnt--) {

		if (isR)
			dq.insert(dq.end() + f- 1, 1);//dq.insert(dq.begin() + f - 1, 1);이렇게 해서 틀렸었음 
		else
			dq.insert(dq.begin() + 1 , 1);
	}

	if (isR) {
		for (int i = 0; i < n; i++) {
			cout << dq.back() << ' ';
			dq.pop_back();
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << dq.front() << ' ';
			dq.pop_front();
		}
	}

}
