#include<iostream>

using namespace std;

int N;//N 1~15
bool numX[16],numY[16]; // 4퀸  /방향 대각선 x+y=0,1,2,3,4,5,6,7,8   \ 방향 대각 N +x-y= 8,7,
int cnt;
int check[31],check2[31];

void NQueen(int y)
{

	if (y == N )
	{
		//cout << "ddddddddd" << endl;
		cnt++;
		return;
		
	}
	for (int i = 0; i < N; i++)
	{
		if (!numX[i] && !numY[y] && !check[i + y] && !check2[N + i - y])
		{
			numX[i] = true; numY[y] = true; check[i + y] = true; check2[N + i - y] = true;
			//cout << i << " "<<y << endl;
			NQueen( y+1);
			numX[i] = false; numY[y] = false; check[i + y] = false; check2[N + i - y] = false;

		}
		
	}
	
}

int main()
{
	//N 1~15
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	NQueen(0);
	cout << cnt;

}