#include<iostream>
#include<cmath>
using namespace std;

int nn,temp;
int num[2200][2200];

int ans[3];
int check;
void division(int x, int y, int n)
{

	check = num[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (num[i][j] != num[x][y])
			{
				
				division(x, y, n/3);
				division(x + n*1/3, y, n/3);
				division(x + n*2/3, y, n/3);
				division(x, y + n * 1 / 3, n / 3);
				division(x + n * 1 / 3, y + n / 3, n / 3);
				division(x + n * 2 / 3,y+ n / 3, n / 3);
				division(x, y + n * 2 / 3, n / 3);
				division(x + n * 1 / 3, y + n * 2 / 3, n / 3);
				division(x + n * 2 / 3, y + n * 2 / 3, n / 3);
				return;

			}
		}
	ans[num[x][y] + 1]++;
	return;
}

int main()
{
	cin >> nn;
	
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			cin >> num[i][j];

	division(0,0,nn);
	
	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}