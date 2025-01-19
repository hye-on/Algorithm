#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001]; 
string a, b;

int main() {
    cin >> a >> b;

    // LCS 길이 계산
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // LCS 복원
    string lcs = "";
    int i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs = a[i - 1] + lcs; 
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << dp[a.size()][b.size()] << endl; 
    if (!lcs.empty()) {
        cout << lcs << endl; 
    }

    return 0;
}
