#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string A, B;
int cache[1002][1002];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;

	
	for(int i=0;i<=A.length();i++)
		for (int j = 0; j <= B.length(); j++)
		{
			if (A[i] == B[j])
			{
				cache[i + 1][j + 1] = cache[i][j] + 1;
			}
			else
				cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
		}
	cout << cache[A.length() ][B.length() ];

}