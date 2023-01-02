#include <iostream>
#include<string>

using namespace std;

int N;
int image[64][64];
int zero, one;
string s="";
void QuadTree(int x,int y,int n)
{
	//cout << s << endl;
	if (n == 0)
		return;
	zero = 0; one = 0;
	for(int i=x;i<x+n;i++)
		for (int j = y; j <y+n; j++)
		{
			if (image[i][j])
				one++;
			else
				zero++;
		}
	if (one == n * n)
	{
		s += "1";
	}
	else if (zero == n * n)
	{
		s += "0";
	}
	else
	{
		s += "(";
		QuadTree(x,y, n / 2);
		QuadTree(x, y + n / 2, n / 2);//0 4 4
		QuadTree(x + n / 2, y ,n / 2);
		QuadTree(x + n / 2, y + n / 2, n / 2);
		s += ")";


	}

}

int main()
{
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			image[i][j] = temp[j]-'0';
		
			
		}
	}
	//s += "(";
	QuadTree(0,0, N);
	cout << s;

}