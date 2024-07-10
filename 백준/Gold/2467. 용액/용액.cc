#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int N;
vector<int>v;

int main() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int left = 0, right = N - 1;

	int ans1=0, ans2=0;
	int num = 0;
	int minN = 2000000001;

	while (left < right) {

		num = v[left] + v[right];
		if (abs(num) <= minN) {
			ans1 = v[left];
			ans2 = v[right];
			minN = abs(num);
		}
		if (num == 0) {
			ans1 = v[left], ans2 = v[right];
			break;
		}
		else if (num > 0)
			right--;
		else
			left++;
		

	}
	cout << ans1<<" "<< ans2;
	
}