#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	int T;
	int N, M,temp;
	cin >> T;
	while (T--) {
		
		cin >> N >> M;
		vector<int>A;
		vector<int>B;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			A.push_back(temp);
		}

		for (int i = 0; i < M; i++)
		{
			cin >> temp;
			B.push_back(temp);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		//cout<<"dddd" << B[0] << " " << B[1] << " " << B[2] << endl;
		int ans = 0;
		int low = 0;
		for (int i = 0; i < N; i++) {
			int  high = B.size() -1, mid;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (B[mid] < A[i])
				{
					low = mid + 1;
				}
				else //if(B[mid] > A[index])
				{
					high = mid - 1;
				}
				// << mid << endl;
			}
			ans += (low);
			//cout << mid << endl;
		//	cout << endl;
		}
		cout << ans << endl;
		ans = 0;

	}
}