#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>
using namespace std;

#define ll long long
int n;

vector<pair<int, pair<int, int>>>c; //r,x,y
vector<int>link[5001];
int answer;
bool visit[5001];

// tuple알아보기


int dfs(int x, int depth) {
	if (visit[x]) return 0;
	visit[x] = true;
	int cnt = depth;
	for (int i = 0; i < link[x].size(); i++) {
		int nx = link[x][i];
		depth = max(depth, dfs(nx, cnt + 1));
	}
	visit[x] = false;
	return depth;
}


bool isIn(pair<int, pair<int, int>>&c1, pair<int, pair<int, int>>&c2) {
	ll r1 = c1.first;
	ll x1 = c1.second.first;
	ll y1 = c1.second.second;

	ll r2 = c2.first;
	ll x2 = c2.second.first;
	ll y2 = c2.second.second;

	long double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	d = sqrt(d);

	if (d > r1 + r2) return false;// 외부에 있음 
	else if (d == 0 || d < abs(r1 - r2))
		return true; //내부에 있음


}
//두 원의 연결을 만들기
void makeLink(int x) {

	bool flag = false;
	//원 x 안에 여러 원이 있을 수 있지만
	// x는 딱 1개의 원에만 속할 수 있음. - 바로 인접한 원
	for (int idx = x + 1; idx < c.size(); idx++) {
		//이미 전 검사에서 연결되었음
		
		//원 1 - 원 3 - 원 5 - 원 7 인 상황에서
		// 원 2 - 원3 연결. 3부터는 이미 검사 되어있기 때문에 종료
		if (isIn(c[x], c[idx])){
			if (!link[idx].empty()) 
				flag = true;
			link[x].push_back(idx);
			link[idx].push_back(x);
			// 그 다음 밖에있는 원을 찾음	
			x = idx;
		}
		if (flag) 
			return;
		
	}
		
	
}

int main() {
	cin >> n;
	c.resize(n + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> c[i].second.first >> c[i].second.second >> c[i].first;
	}
	c[n] = { 10000000,{0,0} };//좌표평면도 큰 원임

	sort(c.begin(), c.end()); //오름차순
	
	//연결을 만들어준다. 
	for (int i = 0; i < c.size(); i++) {
		if (link[i].empty())
			makeLink(i);
	}
	for (int i = 0; i < c.size(); i++)
		answer = max(dfs(i, 0),answer);
	cout << answer;
}