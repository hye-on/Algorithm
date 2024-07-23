#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>>v;//y좌표, x 좌표
int n, m, l, k;//가로 , 세로, 트램플린 한 변 길이, 별똥 별 수

int cal(int x,int y) {
	int tmpCnt = 0;

	for (int i = 0; i < k; i++) {
		int tmpY = v[i].first;
		int tmpX = v[i].second;
		if (x <= tmpX && tmpX <= x + l && y <= tmpY && tmpY <= y+l)
			tmpCnt++;
	}

	
	return tmpCnt;
}

int main() {

	cin >> n >> m >> l >> k;
	v.resize(k);
	int tmpX=0, tmpY=0;
	for (int i = 0; i < k; i++) {
		cin >> tmpX >> tmpY;
		v[i]={ tmpY,tmpX };
	}
	int dir[] = { 1,2,3,4};
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			
				
			cnt = cal(v[i].second, v[j].first); //x,y

			ans = max(cnt, ans);

			
		}
	}
	
	cout << k - ans << endl;
}