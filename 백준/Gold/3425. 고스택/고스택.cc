#include <iostream>
#include <string>
#include <vector>
#include<stack>
#include <algorithm>
using namespace std;
//10:27

#define MAX 1000000000
string s;
bool isError;
void NUM(stack<int>&st, int nn){
    st.push(nn);
}
void POP(stack<int>&st){
    if(!st.empty())
        st.pop(); 
    else{
        isError = true;
    }
}
void INV(stack<int>&st){
    if(!st.empty()){
        int tmp = st.top();
        st.pop();
        st.push(-tmp);
    }else{
        isError = true;
    }
}
void DUP(stack<int>&st){
    if(!st.empty()){
        st.push(st.top());
    }else{
        isError = true;
    }
}
void SWP(stack<int>&st){
    if(st.size()>=2){
        int f_n= st.top(); st.pop();
        int s_n= st.top(); st.pop();
        st.push(f_n);
        st.push(s_n);
    }else{
        isError = true;
    }
}
void ADD(stack<int>&st){
    if(st.size()>=2){
        int f_n= st.top(); st.pop();
        int s_n= st.top(); st.pop();
        
        st.push(f_n+s_n);
        
    }else{
        isError = true;
    }
}

void SUB(stack<int>&st){
    if(st.size()>=2){
        int f_n= st.top(); st.pop();
        int s_n= st.top(); st.pop();
        
        st.push(s_n - f_n);
        
    }else{
        isError = true;
    }
}

void MUL(stack<int>&st){
    if(st.size()>=2){
        int f_n= st.top(); st.pop();
        int s_n= st.top(); st.pop();
        long long re = 1LL*s_n * f_n;
        if(abs(re)>MAX){
            isError=true;
            return;
        }
        st.push(s_n * f_n);
        
    }else{
        isError = true;
    }
}

void DIV(stack<int>&st){
    
    if(st.size()>=2){
        int f_n= st.top(); st.pop();
        int s_n= st.top(); st.pop();
        if(f_n==0){
            isError = true;
            return;
        }
        st.push(s_n / f_n);
        
    }else{
        isError = true;
    }
}

void MOD(stack<int>&st){
    if(st.size()>=2){
        
        int f_n= st.top(); st.pop();
        int s_n= st.top(); st.pop();
        if(f_n==0){
            isError = true;
            return;
        }
        st.push(s_n % f_n);
        
    }else{
        isError = true;
    }
}

void OOB(stack<int>&st){
    if(!st.empty()){
        if(abs(st.top())>MAX)
            isError = true;
    }
}

void goStack(int init_n, vector<pair<string,int>>cmd){
    stack<int>st;
    st.push(init_n);
    for(auto c:cmd){
        if(c.first=="NUM"){
            NUM(st,c.second);
        }else if(c.first=="POP"){
            POP(st);
        }else if(c.first=="INV"){
            INV(st);
        }else if(c.first=="DUP"){
            DUP(st);
        }else if(c.first=="SWP"){
            SWP(st);
        }else if(c.first=="ADD"){
            ADD(st);
        }else if(c.first=="SUB"){
            SUB(st);
        }else if(c.first=="MUL"){
            MUL(st);
        }else if(c.first=="DIV"){
            DIV(st);
        }else if(c.first=="MOD"){
            MOD(st);
        }
        OOB(st);
        if(isError)
            break;
    }

    if(isError || st.size()!=1)
        cout<< "ERROR" <<endl;
    else
        cout<<st.top()<<endl;
    isError = false;

}

int main() {
    bool isEnd = false;
   

    while(true){
        vector<pair<string,int>>cmd;
        while(true){
            
            cin>>s;
            
            if(s=="END"){
                int n =0,num=0;
                cin>>n;
                for(int i=0;i<n;i++){
                    cin>>num;
                    goStack(num,cmd);
                }
                cout<<endl;
                break;
            }else if(s=="QUIT"){
                isEnd=true;
                break;
            }
            int t=0;
            if(s=="NUM")
                cin>>t;
            
            cmd.push_back({s,t});
        }
        if(isEnd)
            break;
    }
    return 0;
}