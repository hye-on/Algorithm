#include<iostream>
#include<deque>
#include<queue>
using namespace std;

int graph[101][101];//-1: 사과 , -2: 자기 자신
int N, K, L;
deque< pair<int, int>>q; //뱀의 r,c 위치
queue<pair<int, char>>qq;
//int snake[101][101];
int xxx, d;
char ccc; //방향을 바꿀 시간과 방향    d=0 오른쪽, d=1 위, d=2 왼쪽, d=3 아래쪽
int tx, ty;

void dummy(int t, int y, int x)
{
	//cout <<t<<" " << "y : " << y << " x : " << x << "   graph : " << graph[y][x] << endl;
	if (y <= 0 || y > N || x <= 0 || x > N || graph[y][x] == -2)//자기 자신과 만나거나 벽을 만나면 게임 끝
	{
		//cout << graph[y][x] << endl;
		cout << t;
		exit(0);
	}
	if (graph[y][x] == -1)//사과를 만나면 몸길이 증가
	{
		q.push_front(make_pair(y, x));
		graph[y][x] = -2;
		
	}
	else//뱀의 꼬리부분 좌표 0으로 바꿔주기
	{
		q.push_front(make_pair(y, x));
		graph[y][x] = -2;
		ty = q.back().first; tx = q.back().second;
		q.pop_back();
		graph[ty][tx] = 0;
	}
	if (t == xxx)//방향을 바꿀 시간이 되면 방향 바꾸기
	{
		//cout << "t  " << t  <<" xxx "<<xxx<<endl;
		if (d == 0)
		{
			if (ccc == 'D')
				d = 3;
			else
				d = 1;
		}
		else if (d == 1)
		{
			if (ccc == 'D')
				d = 0;
			else
				d = 2;
		}
		else if (d == 2)
		{
			if (ccc == 'D')
				d = 1;
			else
				d = 3;
		}
		else
		{
			if (ccc == 'D')
				d = 2;
			else
				d = 0;
		}
	//	cout << "size " << qq.size() << endl;
		if (qq.size() > 0)
		{
			xxx = qq.front().first; ccc = qq.front().second;
			qq.pop();
		}
		//cout << " d  " << d << endl;

	}

	//방향에 따라서 이동할 좌표 정하기
	int dx = x, dy = y;
	if (d == 0)
	{
		dx++;
	}
	else if (d == 1)
		dy--;
	else if (d == 2)
		dx--;
	else
		dy++;
	dummy(t + 1, dy, dx);

}
int main()
{
	cin >> N;
	cin >> K;
	int r = 0, c = 0;
	//행 가로row
	while (K--)
	{
		cin >> r >> c;
		graph[r][c] = -1;
	}
	cin >> L;
	int xx;
	char cc;
	while (L--)
	{
		cin >> xx >> cc;
		qq.push(make_pair(xx, cc));
	}
	graph[1][1] = -2;
	q.push_back(make_pair(1, 1));

	xxx = qq.front().first; ccc = qq.front().second;
	qq.pop();
	d = 0;
	dummy(1, 1, 2);
}