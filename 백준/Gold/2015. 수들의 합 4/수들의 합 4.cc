#include<iostream>
#include<map>
using namespace std;

int N, K;

int num[200002];
int tmp;
map<int, long long>m;
int main() {
	cin >> N >> K;
	long long answer = 0;
	//num 1~N
	m[0] = 1;
	for (int i = 0; i < N; i++) {

		cin >> tmp;
		num[i+1] = num[i] + tmp;
		answer += (m[num[i + 1] - K]);
		m[num[i + 1]]++;


	}

	cout << answer;
}