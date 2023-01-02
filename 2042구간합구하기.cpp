#include<iostream>
#define MAX_TREE (1<<21)



using namespace std;
int N, M, K;
long long a, b, c,dif;

long long num[1000001];
long long sum[MAX_TREE];
//���� �� Ʈ�� �����
void init(int node, int start, int end) {
	if (start == end) {//�� ������ ����.
		
		sum[node] = num[start];
		return;
	}
	else {
		//����� �ڽ� ���鿡 ����
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		sum[node] = sum[node * 2] + sum[node * 2 + 1];
		return;
	}
}

//�� �ٲٱ� �Լ�
void change(long long start, long long end, long long node, long long index ,long long dif)//����: start~end node:������ ����ִ� ����ȣ
{															//index:�迭���� �ٲٰ� ���� ���� �ִ� ��ġ, dif:������ ��
	if (index > end || index < start)
		return;
	
	sum[node] += dif;
	//�ڽĵ鵵 �ٲ��ش�
	if (start == end)return;
	change(start, (start + end) / 2, node * 2, index, dif);
	change((start+end)/2+1,  end, node * 2+1, index, dif);

}

long long sumN(long long start, long long end, long long left, long long right, long long node)
{
	if (start > right || end < left)
		return 0;
	else if (start >= left && end <= right)
		return sum[node];
	else
	{
		return sumN(start, (start + end) / 2, left, right, node * 2)+ sumN((start + end )/ 2+1,end, left, right, node * 2+1);
	}
}

int main()
{

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	//���� �� Ʈ�� �����
	init(1, 0, N-1);
	//cout << sum[1] << "  " << sum[2] << "  " << sum[3] << endl;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)//b ��° ���� c�� �ٲٱ�
		{
			
			//���̸� �������ָ� �ȴ�.
			
			dif = c - num[b - 1];
			num[b - 1] = c;
			
			change(0, N-1, 1, b-1, dif);
			

			

		}
		else if (a == 2)//b��°���� c��°���� �� ���ϱ�
		{
			cout<<sumN(0, N-1, b-1, c-1, 1)<<endl;
		}
	}
}