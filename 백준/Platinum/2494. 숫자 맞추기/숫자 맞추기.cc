#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct State {
    int total_turn = -1;  // 해당 상태까지의 최소 회전 수
    int turn = 0;         // 현재 위치에서의 회전 수
};

int n;
State dp[10000][10];  // [위치][현재숫자]
char start[10000], target[10000];
const int MOD = 10;

int solve(int left_sum, int pos) {
    if (pos == n) {
        return 0;
    }

    // 현재 숫자 계산 (초기값 + 누적 왼쪽 회전)
    int curr_num = (start[pos] + left_sum) % MOD;
    
    // 이미 계산된 상태라면 반환
    int& ret = dp[pos][curr_num].total_turn;
    if (ret != -1) {
        return ret;
    }

    // 오른쪽 회전 횟수 계산
    int right_cnt;
    if (target[pos] > curr_num) {
        right_cnt = curr_num + 10 - target[pos];
    } else {
        right_cnt = curr_num - target[pos];
    }

    // 왼쪽 회전 횟수 계산
    int left_cnt;
    if (target[pos] >= curr_num) {
        left_cnt = target[pos] - curr_num;
    } else {
        left_cnt = target[pos] + 10 - curr_num;
    }

    // 왼쪽과 오른쪽 각각의 경우 계산
    int left_result = solve((left_sum + left_cnt) % MOD, pos + 1) + left_cnt;
    int right_result = solve(left_sum, pos + 1) + right_cnt;

    // 더 적은 회전이 필요한 방향 선택
    if (left_result < right_result) {
        ret = left_result;
        dp[pos][curr_num].turn = left_cnt;
    } else {
        ret = right_result;
        dp[pos][curr_num].turn = -right_cnt;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    string s, t;
    cin >> s >> t;

    // 문자열을 숫자로 변환
    for (int i = 0; i < n; ++i) {
        start[i] = s[i] - '0';
        target[i] = t[i] - '0';
    }

    // 최소 회전 수 출력
    cout << solve(0, 0) << '\n';

    // 경로 역추적 및 출력
    int pos = 0;
    int num = start[0];
    int total_left = 0;

    while (pos < n) {
        cout << pos + 1 << ' ' << dp[pos][num].turn << '\n';
        
        // 왼쪽으로 돌린 경우 누적값 갱신
        if (dp[pos][num].turn > 0) {
            total_left = (total_left + dp[pos][num].turn) % MOD;
        }
        
        pos++;
        if (pos < n) {
            num = (start[pos] + total_left) % MOD;
        }
    }

    return 0;
}