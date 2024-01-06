#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<pair<int,int>> pri_q;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        
         pri_q.push({priorities[i], -i}); 
         q.push({priorities[i], -i});       
        
    }
    
    while(!q.empty()){
        if(q.front().first == pri_q.top().first)
        {
          
            answer++;
            if(!(q.front().second+location))
               return answer;
            pri_q.pop();
            q.pop();
           
        }
        else{
            
            q.push(q.front());
            q.pop();
        }
        
        
    }
    
    return answer;
}