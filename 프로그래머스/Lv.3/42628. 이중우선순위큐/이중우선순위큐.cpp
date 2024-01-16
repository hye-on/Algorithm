#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    priority_queue<int>q;
    priority_queue<int,vector<int>,greater<int>>q2;
    int re_cnt=0;
    for(auto op : operations){
        if(op[0]=='I'){
            cnt++;
            q.push(stoi(op.substr(2)));
            q2.push(stoi(op.substr(2)));
          //  cout<<stoi(op.substr(2))<<endl;
           
        }
        
        
        //최솟값 삭제
       if(!q2.empty() && op[0]=='D' && op[2]=='-'){
           q2.pop();
           re_cnt++;
        }
        
        //최댓값 삭제
        if(!q.empty() && op[0]=='D' && op[2]!='-'){
            q.pop();
            re_cnt++;
        }
        
        if(re_cnt==cnt){
            while(!q.empty())
                q.pop();
            while(!q2.empty())
                q2.pop();
        }
    }
    if(cnt-re_cnt==0){
         answer.push_back(0);
         answer.push_back(0);
    }
    else{
        answer.push_back(q.top());
        answer.push_back(q2.top());
    }

        
    return answer;
}