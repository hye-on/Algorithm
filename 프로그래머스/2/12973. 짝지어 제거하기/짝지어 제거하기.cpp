#include <iostream>
#include<string>
#include<stack>
using namespace std;

stack<char>st;
char tc;
int solution(string s)
{
    int answer = 0;
    for(int i=0;i<s.size();i++){
        if(st.size()!=0){
            tc = st.top();
            if(s[i]==tc)
            {   st.pop();
                continue;
            }
            
        }
        st.push(s[i]);             
    }
    if(st.size()==0)
        answer=1;
    
    return answer;
}