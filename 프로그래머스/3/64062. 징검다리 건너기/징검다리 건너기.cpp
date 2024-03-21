#include <string>
#include <vector>
#include<deque>
#include<iostream>
using namespace std;

deque<pair<int,int>>dq;
int solution(vector<int> stones, int k) {
    int answer = 200000002;
    
    for(int i=0;i<stones.size();i++){
        if(dq.front().second<=i-k) 
            dq.pop_front();
        while(true){
            if(dq.empty())break;
            if(dq.back().first>stones[i])break;
            dq.pop_back();
        }
        dq.push_back({stones[i],i});
        if(i>=k-1)
            answer = min(answer, dq.front().first);
    }
    return answer;
}