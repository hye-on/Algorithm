#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N;
vector<int>num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	num.resize(N);
	bool chk = false;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (num[i] != 0)
			chk = true;

	}
	if (!chk) {
		cout << (N * (N - 1) * (N - 2)) / (3 * 2 * 1);
		return 0;
	}
	sort(num.begin(), num.end());
	long long start = 1, end = N - 1, mid = 0, sum = 0, ans = 0;
	//  -6 -5 -4 -4 0 1 2 2 3 7
	int index = 0;
	while (index<N && num[index] <= 0 ) {
		start = index + 1;
		end = N - 1;
		while (start < end) {
			sum = 0;
			sum = num[index] + num[start] + num[end];
			if (sum == 0)
			{
				
				if (num[start] == num[end])
				{
					ans += (end - start);
					end--;
				}	
				else {
					int l= num[start],l_n = 0, r=num[end], r_n = 0;
					
					while (r == num[end--]) {
						r_n++;

						if (r != num[end]) 
							break;
					}

					while (l == num[start++]) {
						l_n++;
						if (l != num[start])
							break;
					}
					ans+=(r_n*l_n);
					
				}
			}
			else if (sum < 0)
				start++;
			else
				end--;
		}
		index++;


	}
	cout << ans;
}