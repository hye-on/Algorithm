#include <iostream>
#include<vector>
#include<stack>

using namespace std;
//top보다 큰게 들어오면 pop & 저장
//작은게 들어오면 스택에 넣기
//스택끝나면 다 비우기

//3 5 2 7

//9:30
int n;
int cur;
stack<pair<int,int>>st; //숫자, 인덱스
vector<int>ans; 

int main() {
    cin>>n;
    ans.resize(n);
    for(int i=0;i<n;i++){
        cin>>cur;

        while(!st.empty() && st.top().first<cur){
            ans[st.top().second] = cur;
            st.pop();
        }
        st.push({cur,i});
    }
    
    while(!st.empty()){
        ans[st.top().second] = -1;
        st.pop();
    }

    for(auto a :ans)
        cout<<a<<' ';
    
    return 0;
}