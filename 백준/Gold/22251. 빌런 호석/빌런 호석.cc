#include<iostream>
#include<string>

using namespace std;

bool num[10][7] =
{ 
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int cnt[10][10]; // cnt[i][j] i->j 반전 개수 
int n, k, p; //k자리 최대 p개변환 현재 x 층
string x;
int ans;
int kk[6];
void cal() {
	for (int i = 0; i < 10; i++) {
		for (int j = i+1; j < 10; j++) {
			int tmp = 0;
			for (int k = 0; k < 7; k++) {
				if (num[i][k] != num[j][k])
					tmp++;
			}
			cnt[i][j] = tmp;
			cnt[j][i] = tmp;
		}
	}
}

int main() {
	cin >> n >> k >> p >> x;
	//차이 개수 세기
	cal();
	
	while (x.size() < k) {
		x = "0" + x;
	}
	//i부터 n 층 까지 이용가능
	for (int i = 1; i <=n; i++) {
		string toS = to_string(i);
		while (toS.size() < k) {
			toS = "0" + toS;
		}
		int sum = 0;
		for (int j = 0; j < k; j++) {
			//각 자리 마다 변환 개수 0->1은 5
			sum += cnt[x[j]-'0'][toS[j]-'0'];
			
		}
		if (sum <=p && sum>0)
			ans++;
		
	}
	cout << ans;
}