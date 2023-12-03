#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    for(int i=0;i<priorities.size();i++){
        
         q.push({priorities[i], -i}); 
         q2.push({priorities[i], -i});       
        
    }
    
    while(!q2.empty()){
        if(q2.front().first == q.top().first)
        {
           // cout<<q2.front().first<<" " << q2.front().second<<endl;
            answer++;
            if(!(q2.front().second+location))
               return answer;
            q.pop();
            q2.pop();
           
        }
        else{
            
            q2.push(q2.front());
            q2.pop();
        }
        
        // cout<<q.top().first<<" " << q.top().second;
        // q.pop();
        // cout<<endl;
    }
    
    return answer;
}