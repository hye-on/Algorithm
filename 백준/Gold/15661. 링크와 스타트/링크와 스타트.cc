#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> s(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    
    int ans = INT_MAX;

    // 팀사이즈는 1명이상
    for(int team_size = 1; team_size <= n/2; team_size++) {
        
        vector<int> mask(n, 0);
        for(int i = n - team_size; i < n; i++) {
            mask[i] = 1;
        }
        
        
        do {
            vector<int> start_t;
            vector<int> link_t;
            
            // 1이랑 0이랑 다른 팀
            for(int i = 0; i < n; i++) {
                if(mask[i] == 1) {
                    start_t.push_back(i);
                } else {
                    link_t.push_back(i);
                }
            }
            
            // 스타트 팀 계산
            int start_power = 0;
            for(int i = 0; i < start_t.size(); i++) {
                for(int j = 0; j < start_t.size(); j++) {
                    if(i != j) {
                        start_power += s[start_t[i]][start_t[j]];
                    }
                }
            }
            
            // 링크 팀 계산
            int link_power = 0;
            for(int i = 0; i < link_t.size(); i++) {
                for(int j = 0; j < link_t.size(); j++) {
                    if(i != j) {
                        link_power += s[link_t[i]][link_t[j]];
                    }
                }
            }
            
            // 차이 계산
            int ans_tmp = abs(start_power - link_power);
            ans = min(ans, ans_tmp);
            
        } while(next_permutation(mask.begin(), mask.end()));
    }
    
    cout << ans << endl;
    
    return 0;
}