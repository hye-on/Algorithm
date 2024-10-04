#include <string>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

//06:40
// 7:40~8:20

//vector<vector<int>> rc;

int n,m;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    
    deque<int>left;
    deque<int>right;
    deque<deque<int>>pipe;
    
    n = rc.size();
    m = rc[0].size();
    vector<vector<int>> answer(n,vector<int>(m,0));
    pipe.resize(n);
    
    for(int i=0;i<n;i++){
        left.push_back(rc[i][0]);
        right.push_back(rc[i][m-1]);
    }
    
    for(int i = 0 ;i<n;i++){
        for(int j =1;j<m-1;j++){
            pipe[i].push_back(rc[i][j]);
        }
    }
    for(auto s : operations){
        if(s=="ShiftRow"){
            pipe.push_front(move(pipe.back()));
            pipe.pop_back();
            
            left.push_front(left.back());
            left.pop_back();
            
            right.push_front(right.back());
            right.pop_back();
            
            
        }
        else{
            if (m == 2)
            {
                left.emplace_back(right.back());
                right.pop_back();
                right.emplace_front(left.front());
                left.pop_front();
                continue;
            }
            
            pipe[0].push_front(left.front());
            left.pop_front();
            
            left.push_back(pipe[n-1].front());
            pipe[n-1].pop_front();
            
            
            pipe[n-1].push_back(right.back());
            right.pop_back();
            
            right.push_front(pipe[0].back());
            pipe[0].pop_back();
        }
    }
   

   for(int i=0;i<n;i++){
        answer[i][0] = left[i];
        answer[i][m-1] = right[i];
        
    }
    
    for(int i = 0 ;i<n;i++){
        for(int j =1;j<m-1;j++){
            answer[i][j] = pipe[i][j-1];
        }
    }
    
    return  answer;
}