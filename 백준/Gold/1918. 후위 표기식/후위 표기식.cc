#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str, ans;

// 피연산자는 무조건 순서대로 나옴 -> 나오는 즉시 출력
// 연산자
// 바로 뒤의 연산자보다 우선순위 높으면 출력 가능
// 괄호 안은 바로 출력해야함 
int main() {
  
    cin >> str;

    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { //숫자면 바로 출력
            cout << str[i];
            continue;
        }

        if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')') { //괄호안 출력
            while (!st.empty() && st.top() != '(') {
                cout << st.top();;
                st.pop();
            }
            st.pop();
        }
        else if (str[i] == '*' || str[i] == '/') {
            // A*B/C 일 때 A*B먼저 계산. 바로 출력
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-') {
            //A*B+C 이거나 A+B+C 여도 A랑 B를 먼저 연산
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}
