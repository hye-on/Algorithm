#include <iostream>
using namespace std;

int solve(int n, string s) {
    // 불가능한 경우
    if (n == 1 || n == 3) return -1;
    
    // n == 2인 경우 : 01 -> 길이가 0임. 00, 11일경우 1개만 바꾸면 됨. 
    if (n == 2) {
        return (s[0] == s[1]) ? 1 : 0;
    }
    
    // n >= 4인 경우
    bool check = (s[0] == s[n-1]);
    
    if (check) {
        // 양 끝이 같은 경우:   0xxxxx0인경우
        bool flag = (s[1] == s[n-2]); // 01xxxxxx10인 경우  
        return flag ? 2 : 1; // 01xxxx10인 경우    01xxxx01로 2개 바꿈.  01xxxxx00인경우  01xxxxx10으로 1개만 바꿈
    }
    
    // 양 끝이 다른 경우
    // 01xxxxx01 이면 안바꿔도 됨.
    if (s[0] == s[n-2] && s[1] == s[n-1]) {
        return 0;
    }

    // 양끝이 다르면서 안쪽이 같은 경우 01xxxxxx11  00xxxxxx01
    // 1개만 바꿔주면 됨
    // 안쪽 끝이 같은지 체크
    if (s[1] == s[n-2]) {
        return 1;
    }
    
    // 양쪽 크기 비교  000000111111 양쪽으로 갈라져있는 패턴
    int l = 0;
    while (l < n && s[l] == s[0]) {
        l++;
    }
    
    int r = n - 1;
    while (r >= 0 && s[r] == s[n-1]) {
        r--;
    }
    
    int sz1 = l;
    int sz2 = (n - 1) - r;
    
    // 양쪽 크기가 같으면 안바꿔도 됨.
    if (sz1 == sz2) {
        return 0;
    }
    
    // 홀수 길이 && 중간에서 딱 나뉨
    bool odd = (n % 2 == 1);
    bool gap = (r + 1 == l);
    bool mid = (l == n/2 || r == n/2);

    // 1개만 바꿔서는 맞출수가 없음  00011111
    if (odd && gap && mid) {
        return 2;
    }
    // 0011111 홀수이지만 절반은 아닌경우 1개만 바꿔주면 됨. 0011011
    
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solve(n, s) << '\n';
    }
    
    return 0;
}