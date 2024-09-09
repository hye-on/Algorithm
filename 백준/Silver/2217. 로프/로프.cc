#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>num;
int n;
int main() {
	cin >> n;
	num.resize(n);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end(), greater<>());
	int sum = 0;
	int s = 0;
	int maxN = 0;
	for (int i = 0; i < n; i++) {
		s = num[i];
		if(s* (i + 1)>maxN){ //이거를 포함했을 때 총 무게
			maxN = s * (i + 1);
		}
	}

	cout << maxN;
}