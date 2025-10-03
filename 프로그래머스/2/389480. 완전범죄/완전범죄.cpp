#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int itemCnt = info.size();
    
    // dp[i][a][b] : i번째 범죄까지 고려, A 누적 a, B 누적 b 도달 가능 여부
    bool dp[41][121][121];
    memset(dp, false, sizeof(dp));
    
    // 초기 상태: 아무것도 안 한 상태
    dp[0][0][0] = true;
    
    // DP 전이
    for (int i = 0; i < itemCnt; i++) {
        int traceA = info[i][0];
        int traceB = info[i][1];
        
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[i][a][b]) continue;
                
                // i번째 범죄를 A로 처리
                if (a + traceA < n) {
                    dp[i+1][a + traceA][b] = true;
                }
                
                // i번째 범죄를 B로 처리
                if (b + traceB < m) {
                    dp[i+1][a][b + traceB] = true;
                }
            }
        }
    }
    
    // 모든 범죄를 처리한 후 최소 A 값 찾기
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (dp[itemCnt][a][b]) {
                return a;
            }
        }
    }
    
    return -1;
}