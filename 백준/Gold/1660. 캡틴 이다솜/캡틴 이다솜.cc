#include<iostream>
#include<vector>
#include<algorithm>
//#include<cstdlib>
using namespace std;
long long dp[300002];


int main()
{
	int N;
	cin >> N;
	
	fill_n(dp, 300002, 1e9);
	


	vector<int>tetrahedron;
	tetrahedron.push_back(0);
	tetrahedron.push_back(1);
	
	//int temp;
	int a=1, b;
	
	for (int i = 2;; i++)
	{
		b = a + i;
		if (tetrahedron[i - 1] + b > 300000) break;
		tetrahedron.push_back(tetrahedron[i - 1] + b);
		a = b;
	}
	//cout << tetrahedron.size() <<"  "<<tetrahedron[tetrahedron.size()-2]<< endl;
	/*for (int i = 2; i <= 10; i++)
	{
		cout << dp[i] << endl;
	}*/
		for (int i = 0; i < tetrahedron.size(); i++)
		{
			dp[tetrahedron[i]] = 1;
		}

		for (int i = 1; i < tetrahedron.size(); i++)
		{
			for (int j = tetrahedron[i]; j <= N; j++)
			{
				
				dp[j] = min(dp[j], dp[j - tetrahedron[i]] + 1);
				//cout << dp[j]<<endl;

			}
		}
		cout << dp[N];


		/*for (int i = 1; i < 8; i++)
		{
			cout << tetrahedron[i] << endl;
		}*/


	}

	