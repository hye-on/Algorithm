#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int num[4001];
int Mnum[4001];
double sum;
vector<int>v;
int main()
{
	
	/*ù° �ٿ��� �������� ����Ѵ�.�Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.

		��° �ٿ��� �߾Ӱ��� ����Ѵ�.

		��° �ٿ��� �ֺ��� ����Ѵ�.���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.

		��° �ٿ��� ������ ����Ѵ�.*/
	cin >> n;
	int temp;
	int max=(-1*4001), min=4001, midIndex = n / 2 + 1,midean=0,mode=0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		//����
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
		
		if (temp < 0)
		{
			Mnum[-1 * temp]++;
		}
		else
		{
			num[temp]++;
		}
		sum += temp;
	}
	int pN=0, mN=0;
	bool check = false;
	int start = (max > abs(min)) ? max : abs(min);

	for (int i = start; i >= 0; i--)
	{
		

		if (mode < num[i])
		{
			
			mode = num[i];
			v.clear();
			
		}
		 if (mode < Mnum[i])
		{
			

			mode =Mnum[i];
			
			v.clear();
		}
		if (num[i] == mode)
			v.push_back(i);
		if (Mnum[i] == mode)
			v.push_back(-1*i);

		
		pN += num[i];
		mN += Mnum[i];
		
		if (!check&&pN >= midIndex)//�߾Ӱ�
		{
			midean = i;
			check = true;
		}
		else if (!check && mN >= midIndex)
		{
			midean = (-1*i);
			check = true;

		}

	}
	
	/*if (round(sum / n) == -0)
		cout << 0 << endl;
	else*/
	cout << (int)round(sum / n) << endl;//������
	cout << midean << endl;//�߾Ӱ�
	sort(v.begin(), v.end());


	/*for (int i = 0; i < 5000; i++)
	{
		cout << v[i] << endl;
	}*/
	if (v.size() > 1)
		cout << v[1] << endl;
	else
		cout << v[0] << endl;//�ֺ�
	cout << abs(max - min) ;//����
}