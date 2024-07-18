#include<iostream>

using namespace std;

bool num[10000000];
bool Mnum[10000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m,temp;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (temp < 0)
			Mnum[-(temp)] = true;
		else
			num[temp] = true;
	}
	int n,temp2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp2;
		if (temp2 < 0)
			cout << Mnum[-(temp2)] << " ";
		else
			cout << num[temp2] << " ";
	}


	
}