#include<iostream>
#define MAX_TREE (1<<21)



using namespace std;
int N, M, K;
long long a, b, c,dif;

long long num[1000001];
long long sum[MAX_TREE];
//구간 합 트리 만들기
void init(int node, int start, int end) {
	if (start == end) {//더 나눌수 없다.
		
		sum[node] = num[start];
		return;
	}
	else {
		//나누어서 자식 노드들에 저장
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		sum[node] = sum[node * 2] + sum[node * 2 + 1];
		return;
	}
}

//값 바꾸기 함수
void change(long long start, long long end, long long node, long long index ,long long dif)//범위: start~end node:범위가 담겨있는 노드번호
{															//index:배열에서 바꾸고 싶은 값이 있는 위치, dif:변경할 값
	if (index > end || index < start)
		return;
	
	sum[node] += dif;
	//자식들도 바꿔준다
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

	//구간 합 트리 만들기
	init(1, 0, N-1);
	//cout << sum[1] << "  " << sum[2] << "  " << sum[3] << endl;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)//b 번째 수를 c로 바꾸기
		{
			
			//차이를 변경해주면 된다.
			
			dif = c - num[b - 1];
			num[b - 1] = c;
			
			change(0, N-1, 1, b-1, dif);
			

			

		}
		else if (a == 2)//b번째부터 c번째까지 합 구하기
		{
			cout<<sumN(0, N-1, b-1, c-1, 1)<<endl;
		}
	}
}