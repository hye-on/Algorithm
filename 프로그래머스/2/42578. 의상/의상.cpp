#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string,int> clothes_count;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // 종류별로 옷 개수 +1 해서 더하고 -1 개
    // ex ) a 3개 b 2개 -> 4*3 -1 =11
    for(auto clo: clothes){
        if(clothes_count.find(clo[1])==clothes_count.end())
            clothes_count.insert({clo[1],1});
        else
            clothes_count[clo[1]]++;
            
    }
   
    for(auto it : clothes_count)
    {  
        answer*=(it.second+1);
    }
    answer--;
    
    return answer;
}