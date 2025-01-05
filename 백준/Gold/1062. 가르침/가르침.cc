#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int N, K;

bool temp[26];
int check;
int s[51];
int psb, cnt, maxN;
int r;
bool visit = false;
void wordCount()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if ((s[i] & check )== s[i])
			cnt++;
		if (cnt > maxN)
			maxN = cnt;
	}
	return;

}

void backtracking(int depth, int index)
{

	if (depth == psb)//||(r==25&&!visit))
	{

		wordCount();

		if (cnt > maxN)
			maxN = cnt;


		return;
	}
	for (int i = index; i < 26; i++)
	{
		if (!(check&(1<<i)))//방문 안한 경우에
		{

			
			check |= (1 << i);
			backtracking(depth + 1, i + 1);
			check &= ~(1 << i);




		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	if (K < 5)
	{
		cout << 0;
		return 0;
	}

	int end;

	check |= 1 << ('a' - 'a');
	check |= 1 << ('n' - 'a');
	check |= 1 << ('t' - 'a');
	check |= 1 << ('i' - 'a');
	check |= 1 << ('c' - 'a');

	int num = 0;
	string sTemp;
	for (int i = 0; i < N; i++) {
		cin >> sTemp;
		num = 0;
		for (int j = 4; j < sTemp.length() - 4; j++)
			num |= 1 << (sTemp[j] - 'a');
		s[i] = num;

	}
	psb = K - 5;

	//psb개를 뽑기
	backtracking(0, 0);
	cout << maxN;
}
