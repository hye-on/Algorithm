#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;


//2:57
// 맨위에 부터 시작 a위에 있는 곳을 다른 곳으로 옮기고 a이동
//답 봄. 모든 경우를 체크해주는데 중복으로 맵을 이용


int t;
string s;
int charcnt[3];
pair<int, string>tmp[3];
tuple<string, string, string>tu;
tuple<string, string, string>ansS;
map<tuple<string,string,string>, int>visit; // "AABA"  2이면 2번 막대에 AABA가 방문 
string a, b, c;
long answer;
int d;
string na, nb, nc;

void bfs(tuple<string, string, string> start) {
	queue<pair<tuple<string, string, string>,long>>q;

	q.push({start,0});


	while (!q.empty()) {
		if (q.front().first == ansS) {
			answer = q.front().second;
			break;
		}

		tie(a, b, c) = q.front().first;
	
		d = q.front().second;
		q.pop();

		if (a.size() != 0) {
			na = a;
			na.pop_back();
			//a
			if (visit[{na, b + a.back(), c}] == 0) {
				q.push({ {na, b + a.back(), c} ,d + 1 });
				visit[{na, b + a.back(), c}] = 1;

			}
			if (visit[{na, b, c + a.back()}] == 0) {
				q.push({ {na, b , c + a.back()} ,d + 1 });
				visit[{na, b, c + a.back()}] = 1;
			}
		}
		
		if (b.size() != 0) {
			nb = b;
			nb.pop_back();

			if (visit[{a + b.back(), nb, c }] == 0) {
				q.push({ {a + b.back(), nb, c } ,d + 1 });
				visit[{a + b.back(), nb, c }] = 1;
			}
			if (visit[{a, nb, c + b.back() }] == 0) {
				q.push({ {a, nb, c + b.back() } ,d + 1 });
				visit[{a, nb, c + b.back() }] = 1;
			}
		}

		if (c.size() != 0) {

			nc = c;
			nc.pop_back();
			if (visit[{a, b + c.back(), nc}] == 0) {
				q.push({ {a, b + c.back(), nc} ,d + 1 });
				visit[{a, b + c.back(), nc}] = 1;
			}
			if (visit[{a + c.back(), b, nc}] == 0) {
				q.push({ {a + c.back(), b, nc} ,d + 1 });
				visit[{a + c.back(), b, nc}] = 1;
			}
		}
		
		

	}
}
int main() {

	string ansA = "", ansB = "", ansC = "";
	for (int i = 0; i < 3; i++) {
		cin >> t;
		if (t == 0)
			s = "";
		else {
			cin >> s;
		}
		tmp[i] = {t,s};
		for (int j = 0; j < t; j++) {
			charcnt[s[j] - 'A']++;
			if (s[j] == 'A')
				ansA += 'A';
			else if (s[j] == 'B')
				ansB += 'B';
			else
				ansC += 'C';
		}
		
	}
	
	ansS = { ansA,ansB,ansC };
	
	tu = { tmp[0].second,tmp[1].second,tmp[2].second };
	bfs(tu);
	cout << answer;
	
}