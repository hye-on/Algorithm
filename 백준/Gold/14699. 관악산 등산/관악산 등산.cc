#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M,nowH,nowN,toN;

//vector<int>shelter[5001];
//int shelter[5003];
int dp[5001];
vector<int>link[5001];
vector<pair<int, int>>shelter;//높이,
int high[5001];

void dfs()
{

}

int main()
{
	cin >> N >> M;
	int temp,a,b;
	for (int i = 1; i <=N; i++)
	{
		cin >> high[i];
		shelter.push_back(make_pair(high[i], i));
	}

	sort(shelter.begin(), shelter.end(), greater<>());
	
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
		
	}
	for (int i = 1; i <= N; i++)
		dp[i] = 1;

	for (int i = 0; i < N; i++)
	{
		nowH = shelter[i].first;
		nowN = shelter[i].second;
		for (int j = 0; j < link[nowN].size(); j++)
		{
			toN = link[nowN][j];
			if (nowH > high[toN])
				dp[toN] = max(dp[toN], dp[nowN] + 1);
		}
	}
	for (int i = 1; i <= N; i++)
		cout << dp[i] << "\n";

	
}