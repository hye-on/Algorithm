#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string word1, word2;
int main() {
    
    cin >> word1;
    cin >> word2;

    int fromSize = word1.size();
    int toSize = word2.size();

    vector<vector<int>>dp(fromSize + 1, vector<int>(toSize + 1, 0));

    for (int i = 1; i <= fromSize; i++)
        dp[i][0] = i;

    for (int i = 1; i <= toSize; i++)
        dp[0][i] = i;

    for (int i = 1; i <= fromSize; i++) {
        for (int j = 1; j <= toSize; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else // 삭제, 교체, 추가 
                dp[i][j] = 1 + min({ dp[i - 1][j],dp[i - 1][j - 1],dp[i][j - 1] });
        }
    }
    cout<< dp[fromSize][toSize];
}