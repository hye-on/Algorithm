#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long n;

//3:50

int main() {
	cin >> n;

	vector<vector<long long>>num(n, vector<long long>(4));

	vector<long long>left;
	vector<long long>right;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num[i][j];
		}
	}
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			left.push_back(num[i][0] + num[j][1]);
			right.push_back(num[i][2] + num[j][3]);
		}
	}

	//이분 탐색을 위해 오른쪽 정렬 - map으로도 풀어보기
	sort(right.begin(), right.end());
	long long ans = 0;
	for (int i = 0; i < left.size(); i++) {
		long long f = left[i]*-1;
		auto it1 = upper_bound(right.begin(), right.end(), f);
		auto it2 = lower_bound(right.begin(), right.end(), f);
		
		ans += it1 - it2;
	
	}

	
	cout << ans;

}