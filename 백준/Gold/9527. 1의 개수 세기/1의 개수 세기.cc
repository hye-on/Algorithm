#include<iostream>


using namespace std;
//https://yiyj1030.tistory.com/490
//다시 풀기
long long a, b;
long long dp[55]; // 10의 16승은 2진수로 55자리 까지

long long cal(long long x) {
	//결국 0번비트의 값을 더해야 한다.
	long long  num = x & 1;//x가 홀수면 1 짝수면 0
	for (int i = 54; i > 0; i--) {
		if (x & (1LL << i)) { //최상위 비트가 1이면

			num += dp[i - 1] + (x - (1LL << i) + 1);//x가 18이면 18 - 16 
			x -= 1LL << i; //최상위 비트 1의 개수를 세어주기 위해서 
		}
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[0] = 1;
	for (int i = 1; i < 55; i++)
		dp[i] = dp[i-1] * 2 + (1LL << i);

	cin >> a >> b;

	long long ans = cal(b) - cal(a - 1);
	cout << ans;


}