#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int>v(100001);
vector<bool>contain(100001);
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long ans = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		for ( ; j < n; j++) {

			//포함되어 있지 않으면 
			if (!contain[v[j]]) {
				contain[v[j]] = true;
			}
			else {
				
				break;
			}
		}
		ans += (j - i);
		contain[v[i]] = 0;
	}
	cout << ans;
}