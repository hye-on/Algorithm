#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, c;

//중간에서 만나기
int num[30];

void calSum(int idx,int endIdx, long long sum, vector <long long>& v) {
	if (idx == endIdx) {
		v.push_back(sum);
		return;
	}

	calSum(idx + 1, endIdx, sum, v); //안 더하기
	calSum(idx+1,endIdx, sum+num[idx], v); // 더하기
	
}

int main() {
	cin >> n >> c;
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<long long>left;
	vector<long long>right;
	
	calSum(0, n / 2, 0, left);
	calSum(n / 2, n , 0, right);

	//이분 탐색을 위해 정렬
	sort(right.begin(), right.end());


	long long ans = 0;
	for (int i = 0; i < left.size(); i++)
		ans += upper_bound(right.begin(), right.end(), c - left[i]) - right.begin();



	cout << ans;
}


