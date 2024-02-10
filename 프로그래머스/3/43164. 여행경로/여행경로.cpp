#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> answer;
int city_cnt;
multimap<string,string>cnnt;
vector<string>route;
map<string,string>visit;
bool chk;
void dfs(int visit_cnt,string airport, vector<string>& route){
    if(visit_cnt==city_cnt){
        if(chk)
            return;
        answer=route;
        chk=true;
        return;
    }
    if(visit_cnt>city_cnt)
        return;
    vector<string> next_airport;
    //vector로 옮기기
    auto range =cnnt.equal_range(airport);

    for (auto it = range.first; it != range.second; ++it) {
        next_airport.push_back(it->second);
    }
    //오름차순 정렬
     sort(next_airport.begin(),next_airport.end());
    
    
    for(int i=0;i<next_airport.size();i++){
        route.push_back(next_airport[i]);
        //삭제
        string keyToRemove = airport;
        string valueToRemove = next_airport[i];

        auto range = cnnt.equal_range(keyToRemove);

        for (auto it = range.first; it != range.second; ) {
            if (it->second == valueToRemove) {
                it = cnnt.erase(it); 
                break;
            } else {
                ++it;
            }
        }
        dfs(visit_cnt+1,next_airport[i],route);
        route.pop_back();
        cnnt.insert({airport,next_airport[i]});
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    city_cnt = tickets.size();
    for(int i=0;i<city_cnt;i++){
        cnnt.insert({tickets[i][0],tickets[i][1]});
    }
    route.push_back("ICN");
    dfs(0,"ICN",route);
    return answer;
}