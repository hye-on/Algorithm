#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


unordered_map<string,multimap<int,int,greater<int>>> aM;
map<string, int> gM;

bool cmp(pair<string,int>a, pair<string,int>b){
    
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int album_size = genres.size();
    for(int i = 0; i< album_size ; i++){
        
        aM[genres[i]].insert({plays[i],i});
        gM[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> gV(gM.begin(), gM.end());
    sort(gV.begin(), gV.end(), cmp);

    for(auto v : gV){
        auto it = aM.find(v.first);
        auto currentElement = it->second.begin();

        for (int i = 0; i < 2 && currentElement != it->second.end(); ++i, ++currentElement)
           answer.push_back(currentElement->second );

    }
    
    return answer;
}