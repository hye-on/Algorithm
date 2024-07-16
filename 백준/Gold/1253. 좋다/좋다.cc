#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;
int n;
int sum = 0;

int main() {
	cin >> n;

	v.resize(n);

	for(int i=0;i<n;i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int find  = 0;
	int left=0, right=0;
	int ans = 0;
	for (int i = n - 1; i >=0 ; i--) {
		left = 0;
		right = n-1;
		if (left == i)
			left++;
		if (right == i)
			right--;
		while (left<right) {
			sum = v[left] + v[right];
			
			if (sum == v[i]) {
				//cout << v[left] <<" "<< v[right] << endl;
				ans++;
				break;
			}
			
			if (sum < v[i])
				left++;
			else
				right--;
			if (left == i)
				left++;
			if (right == i)
				right--;
		}
	}
	cout << ans;

}