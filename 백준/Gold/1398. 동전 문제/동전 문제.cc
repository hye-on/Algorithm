#include <iostream>
#include <algorithm>
#include<cmath>
#include<queue>

using namespace std;

//2:02 ~ 3:09

int T;
int dp[101];

int main() {
    cin >> T;
    for (int i = 0; i <= 100; i++)
        dp[i] = i;
    dp[1] = 1;
    dp[10] = 1;
    dp[25] = 1;
    dp[100] = 1;
   
    int coin[] = { 1,10,25,100 };

    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < 4; j++) {
            if (i - coin[j] > 0) {
                dp[i] =  min( dp[i - coin[j]] + 1, dp[i] );
            }
        }
    }
 
       
    long long tmp=0;
    int num = 0;
    while (T--) {
        cin >> tmp;
        int ans = 0;
        while (tmp) {
            num = tmp % 100;
            ans += dp[num];
            tmp /= 100;
        }
        cout << ans << "\n";
    }
}