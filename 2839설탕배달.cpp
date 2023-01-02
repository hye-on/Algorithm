#include<iostream>
#include<algorithm>

using namespace std;

int sugar[5001];



int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 5001; i++)
		sugar[i] = 5000;

	sugar[3] = 1;
	sugar[5] = 1;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 3; j <= i; j++)
		{
			
			sugar[i] = min(sugar[j] + sugar[i - j],sugar[i]);
			
		}
	}
	if (sugar[n] == 5000)
		cout << -1;
	else
		cout << sugar[n];
}