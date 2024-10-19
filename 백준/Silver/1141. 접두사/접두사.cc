#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() > b.length())
		return true;
	else
		return false;
}


int main()
{
	int N, cnt = 1, max = -1;
	bool check;
	int answer = 0;
	cin >> N;
	string head[50];

	for (int i = 0; i < N; i++)
	{
		cin >> head[i];

	}
	sort(head, head + N, compare);

	
	for (int i = 1; i < N; i++)
	{
		check = true;
		for (int j = i-1; j >= 0; j--)
		{
			//cout << i << "  " << j << endl;
			if (head[j].find(head[i])==0)
			{
				//cout << head[i] << " "<<head[j] << endl;
				check = false;
			}
		}
		if (check)
			cnt++;
	}
	cout << cnt;

}