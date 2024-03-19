#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

priority_queue<int>q;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(int i=0;i<works.size();i++){
        q.push(works[i]);
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        if(q.empty())
            break;
        tmp =q.top();
        q.pop();
        if(tmp!=1)
            q.push(--tmp);
    }
    
    while(!q.empty()){
        answer+= (long long)(q.top()*q.top());
        q.pop();
    }
    
    return answer;
}