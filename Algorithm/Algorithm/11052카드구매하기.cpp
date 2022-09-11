#include<iostream>
#include<algorithm>

using namespace std;

int N;
int num[10001];
int dp[10001];
int main()
{
	cin >>  N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		dp[i] = num[i];
	}

	
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i/2; j++)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout<<dp[N];


}