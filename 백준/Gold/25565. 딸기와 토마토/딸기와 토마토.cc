#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> b(n, vector<int>(m));
    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> b[i][j];
            if(b[i][j]) cnt++;
        }
    }
    
    int ov = 2 * k - cnt;
    cout << ov << "\n";
    
    if(ov == 0) return 0;

    //겹치는 지점 찾기
    if(ov == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!b[i][j]) continue;

                //양방향 탐색
                bool h = false;
                if((j > 0 && b[i][j-1]) || (j < m-1 && b[i][j+1])) h = true;
                
                bool v = false;
                if((i > 0 && b[i-1][j]) || (i < n-1 && b[i+1][j])) v = true;
                
                if(h && v) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    
    int r1 = n, r2 = -1, c1 = m, c2 = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[i][j]) {
                r1 = min(r1, i);
                r2 = max(r2, i);
                c1 = min(c1, j);
                c2 = max(c2, j);
            }
        }
    }
    
    if(c1 == c2) {
        int st = r1 + (cnt - k);
        for(int i = 0; i < ov; i++) {
            cout << st + i + 1 << " " << c1 + 1 << "\n";
        }
    } else {
        int st = c1 + (cnt - k);
        for(int i = 0; i < ov; i++) {
            cout << r1 + 1 << " " << st + i + 1 << "\n";
        }
    }
    
    return 0;
}