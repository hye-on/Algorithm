#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

//10:20

//되돌아갈 시점을 미리 모아서 저장해둔다.
//최근 시점과 삭제는 스택을 이용
//a, s, t
int n;
map<int,stack<int>>memory;
stack<int>t;
int main() {
    cin>>n;
    vector<pair<char,int>>query(n+1);
    
    char q ='q';
    int num=0;
    for(int i=1;i<=n;i++){
        cin>>q;
        if(q!='s')
            cin>>num;
        query[i] = {q,num}; 
        if(q=='t'){
            memory[num-1] = t;
        }
    }
    stack<int>ps_list;
    
    for(int i=1;i<=n;i++){
        char cmd = query[i].first;
        int num = query[i].second;

        if(cmd=='a'){
            ps_list.push(num);
        }else if(cmd=='s'){
            if(!ps_list.empty())
                ps_list.pop();
        }else if(cmd=='t'){
            ps_list = memory[num-1];
            //cout<<"fasfd "<<num<<" "<<ps_list.size()<<endl;
            
        }

        if(!ps_list.empty())
            cout<<ps_list.top()<<'\n';
        else
            cout<<"-1"<<'\n';

        if(memory.find(i)!=memory.end()){
            memory[i] = ps_list;
            //cout<<"??  "<<i<<"  "<<memory[i].size()<<endl;
        }
        
        
    }
    
    return 0;
}