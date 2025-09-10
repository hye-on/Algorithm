#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int>name_idx;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    answer.resize(enroll.size());
    
    for(int i=0;i<enroll.size();i++){
        name_idx[enroll[i]] = i;
    }
    
    
    for(int i=0;i<seller.size();i++){
        string current = seller[i];
        int money = amount[i]*100;
        
        while(current != "-" && money > 0) {
            auto it = name_idx.find(current);
            if(it == name_idx.end()) break;
            
            int cur_idx = it->second;
            int fee = money / 10;
            
            if(fee < 1) {
                // 1원 미만
                answer[cur_idx] += money;
                break;
            }
            
            answer[cur_idx] += money - fee;  
            money = fee;  
            current = referral[cur_idx];  // 추천인
        }
    }
    
    return answer;
}