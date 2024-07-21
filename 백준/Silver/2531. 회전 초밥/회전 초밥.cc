#include<iostream>
#include<algorithm>

using namespace std;

int n, d, k, c;//접시, 초밥 가짓수, 연속 접수 수, 쿠폰 번호 

int belt[30001];
int rice[3001];
int idx;
int cnt;
int ans;

int main() {

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
		cin >> belt[i];
	
	int j = 0;
	for (int i = 0; i < n; i++) {
		//개수 세기
		
		for (; j < i + k; j++) {
			idx = j % n;
			//cout << "i " << i << " j  " << idx << endl;

			//rice 추가 없었다면 cnt 추가
			if (!rice[belt[idx]])
				cnt++;
			rice[belt[idx]]++;
		}

		//쿠폰 고려 후 최댓값 갱신
		if (!rice[c]) {
			ans = max(ans, cnt + 1);
		}
		else {
			ans = max(ans, cnt );

		}
			
		//i 번째 1빼주기
		rice[belt[i]]--;
		if (!rice[belt[i]])
			cnt--;
		/*cout << i << "번째  " << belt[i] << endl;
		for (int i = 0; i < 50; i++) {
			if (rice[i] != 0)
				cout << i << " ";
		}
		cout << "cnt " << cnt << endl;
		cout << endl;
		cout << "======" << endl;*/
	}
	cout << ans;
}