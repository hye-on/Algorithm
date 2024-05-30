#include<iostream>
#include<queue>
using namespace std;
int T;
int k;
long long n;
char c;
int cnt;
int tmp;
bool visit[1000001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	while (T--) {
		cin >> k;
		priority_queue<pair<long long,int>>q;
		priority_queue<pair<long long,int>>mq;
		cnt = 0;
		tmp = 0;
		while (k--) {
			
			cin >> c >> n;
			if (c == 'I') {
				q.push({n,k});
				mq.push({ -n,k });
				tmp++;
				visit[k] = true;
				
			}
			else {
				//q 비우기

					if (n == 1) {
						//이미 삭제된 수 삭제
						while (!q.empty() && !visit[q.top().second])
							q.pop();
						if (!q.empty())
						{
							visit[q.top().second] = false;
							q.pop();
						}
						
					}
					else {

						while (!mq.empty() && !visit[mq.top().second])
							mq.pop();
						if (!mq.empty()) {
							visit[mq.top().second] = false;
							mq.pop();

						}
						
					}
				
				
			}
		}
		
		//이미 삭제된 수 삭제
		while (!q.empty() && !visit[q.top().second])
			q.pop();

		while (!mq.empty() && !visit[mq.top().second])
			mq.pop();

		if (q.size() == 0 && mq.size() == 0)
			cout << "EMPTY" << endl;
		else {
				
			cout << q.top().first << " " << -mq.top().first << endl;
			
		}

	}
}