#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector<int>v;
int N,tmp;
stack<pair<int, int>>s;
int main() {
	cin >> N;
	v.resize(N+1);
	
	for (int i = 1; i <=N; i++) {
		cin >> tmp;
		//비어 있으면 0
		if (s.empty()) {
			v[i] = 0;
			s.push({ tmp,i });
			continue;
		}

		//top보다 작을 때까지 pop
		if (s.top().first <= tmp) {
			while (!s.empty() && s.top().first < tmp) {
				s.pop();
			}

			if (s.empty())
				v[i] = 0;
			else
				v[i] = s.top().second;
		}
		else {
			v[i] = s.top().second;
		}

		s.push({ tmp,i });
	}

	for (int i = 1; i <= N; i++)
		cout << v[i] << " ";
}