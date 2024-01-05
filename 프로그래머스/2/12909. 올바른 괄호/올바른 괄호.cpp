#include<string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> pa;
bool solution(string s)
{
    bool answer = true;
    
    //(이면 스택에 넣기
    for(auto c : s){
        if(c=='(')
            pa.push('(');
        else{
            
            //스택 비어 있으면 false
            if(pa.empty())
                return answer=false;
             //)이면 스택에서 뺴기
            pa.pop();
                
        }
    }
    if(!pa.empty())
        return answer = false;
   
    
    //스택 남아있으면 false
    
    
    return answer;
}