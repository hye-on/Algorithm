#include<iostream>

using namespace std;
int N, M,K,sum; //N�ϵ��� M ����
int num[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	int left=1, right=sum, mid,cnt ,ans=sum;//�� left�� 0���� ���۵Ǹ� �ȵɱ�?
	bool chk = false;
	
	while (left <=right)
	{
		
		mid = (left + right) / 2;
		K = mid;
		cnt = 1;
		for (int i = 0; i < N; i++)
		{
			if (num[i] > mid)
			{
				chk = true;
				break;
			}
			if (K >= num[i])
			{
				K -= num[i];
				
			}
			else//���ڶ�� �Ǹ� ���� �ݾ��� ���忡 ����ְ� �ٽ� K���� �����Ѵ�. 
			{
				K = mid;
				cnt++;
				K -= num[i];
				
			}

		}
	//	cout<<right<<"  "<<left<<"  " << mid << endl;
		if (cnt > M || chk)
		{
			left = mid + 1;
			chk = false;
		}
		else if (cnt <= M)
		{
			ans = mid;
			right = mid - 1;
		}
	
	}
	
	cout << ans;
}