#include<iostream>

using namespace std;

int main()
{
	long long X, Y, cnt=0;
	long long win;
	long long percent;
	int low = 0, high = 1000000000;
	cin >> X >> Y;
	percent =Y*100 / X;
	//cout << percent << endl;
	win = percent;
	

	if (percent >= 99)
		low = -1;
	else
	{
		while (low <= high)
		{

			int mid = (low + high) / 2;

			

			win = (100 * (Y + mid)) / (X + mid);

			if (percent>= win)
			{

				low = mid + 1;

			}

			else

				high = mid - 1;

		}
	}
	cout << low;
	
	

}