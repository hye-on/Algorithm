#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 10까지 있는 이유 : 10번 돌리나 20번 돌리나 그 이후 다이얼의 미치는 영향은 똑같다.
    // dp[i][j] = k : i번째까지 최소 회전 횟수가 k이다. 각 경우는 왼쪽으로 총 j번 돌렸을 때 
    int dp[10001][10]; 

    memset(dp, 0x3f, sizeof(dp)); //10억으로 초기화 

    int n;
    cin >> n;

    int a[10001], b[10001];
    string s, t;
    cin >> s >> t;

    //숫자로 바꾼다. 
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
        b[i] = t[i - 1] - '0';
    }

    //초기화 
    for (int i = 0; i < 10; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            int left_cnt = (b[i] - (j + a[i]) + 20) % 10; // 0 - (9+9) 일수도 있어서 +20
            int right_cnt = (10 - left_cnt) % 10;

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + right_cnt); //오른쪽으로 돌릴 경우 j는 그대로
            dp[i][(j + left_cnt) % 10] = min(
                dp[i][(j + left_cnt) % 10],
                dp[i - 1][j] + left_cnt
            );
        }
    }

    int answer = 1e9;
    for (int i = 0; i < 10; i++) {
        answer = min(answer, dp[n][i]);
    }

    cout << answer << '\n';
    return 0;
}