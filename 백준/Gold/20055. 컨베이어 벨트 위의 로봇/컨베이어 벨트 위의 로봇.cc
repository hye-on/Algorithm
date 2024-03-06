#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, bool>>belt;
int N, K;
int start, finish;
int cnt_zero;
int ans;
int idx,to_idx;
//벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
//가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.만약 이동할 수 없다면 가만히 있는다.
//로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
//올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
//내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.그렇지 않다면 1번으로 돌아간다.
//종료되었을 때 몇 번째 단계가 진행 중이었는지 구해보자.가장 처음 수행되는 단계는 1번째 단계이다


void move() {
	idx = finish;
	if (belt[idx].second)
		belt[idx].second = false;
	idx--;
	for (int i = N-2; i >= 0; i--,idx--) {
		//로봇이 존재하고, 앞에 로봇없고, 내구도가 남아있으면 1전진 
		if (idx < 0)
			idx = 2 * N - 1 ;
		
		to_idx = idx + 1;
		if (to_idx >= 2 * N)
			to_idx = 0;
		//to_idx = idx + 1 == 2 * N ? 0 : idx + 1;
		if (belt[idx].second && !belt[to_idx].second && belt[to_idx].first>0) {
			//cout << "idx " << idx << endl;
			//cout << "robot :" << idx << " to robot : " << to_idx << "  " << "belt : " << to_idx << endl;

			belt[idx].second = false;
			belt[to_idx].second = true;
			belt[to_idx].first--;
			if (belt[to_idx].first == 0)
				cnt_zero++;
			
		}

	}
	

}
void rotate() {
	belt[finish].second = false;
	start--;
	finish--;
	if (start == -1)
		start = 2 * N - 1;
	if (finish == -1)
		finish = 2 * N - 1;
	
	
}
int main() {
	cin >> N >> K;
	belt.resize(2 * N + 1);
	for (int i = 0; i < N * 2; i++) {
		cin >> belt[i].first;
	}

	start = 0, finish = N - 1;
	int d = 40;
	while (true) {

		//회전하기 
		rotate();
		//로봇움직이기
		move();
		
		//로봇올리기
		if (belt[start].first > 0) {
			belt[start].first--;
			belt[start].second = true;
			if (belt[start].first == 0)
				cnt_zero++;
		}
	
		ans++;
		if (cnt_zero >= K)
			break;
		
	}
	cout << ans;

}