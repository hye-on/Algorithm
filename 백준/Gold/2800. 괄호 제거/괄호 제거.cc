#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<regex>
using namespace std;
//map 공부
//백터 초기화 0으로
string s;
vector<pair<int, int>>idx;
vector<string>ans;
int end_idx;
vector<bool>visit;
string t;
void backtracking( int p,int depth , int stop_idx) {

	if (depth == stop_idx) {
		//@제거해서 ans에 담기
		//cout << "dd " << t << endl;
		ans.push_back(regex_replace(t, regex("@"), ""));
		return;
	}
	for (int i = p; i < end_idx; i++) {
		if (!visit[i]) {
			t[idx[i].first] = '@';
			t[idx[i].second] = '@';
			visit[i] = true;
			backtracking( i + 1, depth + 1, stop_idx);
			t[idx[i].first] = '(';
			t[idx[i].second] = ')';
			visit[i] = false;
		}
	}
	
}
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			idx.push_back({ i,0 });
		else if (s[i] == ')') {
			for (int j = idx.size() - 1; j >= 0; j--) {
				if (idx[j].second == 0) {
					idx[j].second = i;
					break;
				}
			}
		}
	}
	end_idx = idx.size();
	
	
	visit.resize(end_idx);

	for (int i = 0; i < end_idx; i++) {
		fill(visit.begin(), visit.end(), false);
		t = s;
		backtracking(0,0, i + 1);
		
	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (auto a : ans) {
		cout << a<< endl;
	}
}

