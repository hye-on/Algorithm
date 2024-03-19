#include<iostream>
#include<algorithm>

using namespace std;

int city[101][101];
int n, m;

int main()
{
	cin >> n;
	cin >> m;
	//입력   a->b로 가는 버스 중에서 더 짧은것을 입력
	int a, b, cost;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> cost;
		if(!city[a][b] || city[a][b]>cost)//비용은 자연수이므로 0이면 아직 버스가 없다는 뜻
			city[a][b] = cost;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j && city[i][j] == 0)
				city[i][j] = 1000000000;
		}
		
	}
	//모든 경로에 대해  어느 k 지점을 들렸다 가는 비용 계산
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j || i == k || k == j)
					continue;
				/*if (city[i][k] == -1 || city[k][j] == -1)
					continue;
				if (city[i][j] == -1)
					city[i][j] = city[i][k] + city[k][j];*/
				
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == 1000000000)
				cout << '0';
			else
				cout << city[i][j];
			cout << ' ';
		}
		cout << "\n";
	}

		
}