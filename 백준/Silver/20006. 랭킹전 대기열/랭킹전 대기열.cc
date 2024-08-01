#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int p, m;
string player;
int score;
vector<pair<string, int>>num[301]; //이름, 점수


int main() {

	cin >> p >> m;
	int idx = 0;
	int roomCnt = 0;
	for (int i = 0; i < p; i++) {
		cin >> score >> player;
		for (int j = 0; j <=roomCnt; j++) {
			if (num[j].size() == m)
				continue;
			if (i!=0 && num[j].size()>0 && num[j].size()<m &&  abs(num[j][0].second - score) <= 10) {
				num[j].push_back({ player,score });
				
				break;
			}
			else if(j==roomCnt){//들어갈 수 있는 방이 없었을 때 
				num[roomCnt++].push_back({ player,score });
				break;
				
			}
			

		}
	}

	for (int i = 0; i < roomCnt; i++) {
		if (num[i].size() == m) {
			cout << "Started!" << "\n";
			sort(num[i].begin(), num[i].end());
			for (auto g : num[i])
				cout << g.second << " " << g.first << "\n";
		}
		else {
			cout << "Waiting!" << "\n";
			sort(num[i].begin(), num[i].end());
			for (auto g : num[i])
				cout << g.second << " " << g.first << "\n";
		}
	}

	

}