#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int n;

bool compare(string a, string b) {
    // 문자열 비교를 위한 인덱스
    int a_pos = 0, b_pos = 0;
    
    // 두 문자열을 끝까지 비교
    while (a_pos < a.size() && b_pos < b.size()) {
        // 현재 위치에서 둘 중 하나만 숫자면 숫자가 먼저
        if (isdigit(a[a_pos]) && !isdigit(b[b_pos])) {
            return true;
        } else if (!isdigit(a[a_pos]) && isdigit(b[b_pos])) {
            return false;
        } 
        // 둘 다 문자면 연속된 문자 부분 비교
        else if (!isdigit(a[a_pos]) && !isdigit(b[b_pos])) {
            string a_tmp = "";
            int a_idx = a_pos;
            for (int i = a_pos; i < a.size(); i++) {
                if (!isdigit(a[i]))
                    a_tmp += a[i];
                else {
                    a_idx = i;
                    break;
                }
            }
            if (a_idx == a_pos) a_idx = a.size(); // 문자열 끝까지 문자인 경우
            
            string b_tmp = "";
            int b_idx = b_pos;
            for (int i = b_pos; i < b.size(); i++) {
                if (!isdigit(b[i]))
                    b_tmp += b[i];
                else {
                    b_idx = i;
                    break;
                }
            }
            if (b_idx == b_pos) b_idx = b.size(); // 문자열 끝까지 문자인 경우
            
            // 문자 부분이 다르면 결과 반환
            if (a_tmp != b_tmp) {
                // 대소문자 조건 비교
                for (int i = 0; i < min(a_tmp.size(), b_tmp.size()); i++) {
                    char a_char = tolower(a_tmp[i]);
                    char b_char = tolower(b_tmp[i]);
                    
                    if (a_char != b_char) 
                        return a_char < b_char;
                    
                    if (a_char == b_char && islower(a_tmp[i]) != islower(b_tmp[i]))
                        return isupper(a_tmp[i]);
                }
                return a_tmp.size() < b_tmp.size();
            }
            
            // 문자 부분이 같으면 인덱스 이동
            a_pos = a_idx;
            b_pos = b_idx;
        }
        // 둘 다 숫자면 비교
        else if (isdigit(a[a_pos]) && isdigit(b[b_pos])) {
            // 앞의 0 개수 세기
            int a_zero = 0;
            int a_idx = a_pos;
            while (a_idx < a.size() && a[a_idx] == '0') {
                a_zero++;
                a_idx++;
            }
            
            int b_zero = 0;
            int b_idx = b_pos;
            while (b_idx < b.size() && b[b_idx] == '0') {
                b_zero++;
                b_idx++;
            }
            
            // 숫자 부분 추출
            string a_num = "";
            while (a_idx < a.size() && isdigit(a[a_idx])) {
                a_num += a[a_idx++];
            }
            
            string b_num = "";
            while (b_idx < b.size() && isdigit(b[b_idx])) {
                b_num += b[b_idx++];
            }
            
            // 숫자가 다르면 결과 반환
            if (a_num.size() != b_num.size()) {
                return a_num.size() < b_num.size();
            } else if (a_num != b_num) {
                return a_num < b_num;
            } else if (a_zero != b_zero) {
                return a_zero < b_zero;
            }
            
            // 숫자 부분이 같으면 인덱스 이동
            a_pos = a_idx;
            b_pos = b_idx;
        }
    }
    
    // 한 문자열이 끝났으면 더 짧은 문자열이 먼저
    return a_pos >= a.size() && b_pos < b.size();
}

int main() {
    cin >> n;
    vector<string> v(n);
    
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), compare);
    
    for (auto vv: v)
        cout << vv << '\n';
    
    return 0;
}