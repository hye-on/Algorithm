#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>d;
int answer;
int main() {
	cin >> N;
	d.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> d[i];
	}
	
	int left = 0, right = N - 1;

	while (left + 1 < right) {
		answer = max(answer, (right - left - 1) * min(d[left], d[right]));
		if (d[left] < d[right])
			left++;
		else
			right--;
	}
	cout << answer;
}