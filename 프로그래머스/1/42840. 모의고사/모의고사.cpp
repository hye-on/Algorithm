#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first>b.first)
        return true;
    else if(a.first<b.first)
        return false;
    else{
        if(a.second<b.second)
            return true;
        else 
            return false;
    }
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int,int>>cnt ={ {0,1},{0,2},{0,3}};
    int one[] = {1,2,3,4,5};
    int two[] = { 2, 1, 2, 3, 2, 4, 2, 5};
    int three[] ={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int one_size =5;
    int two_size = 8;
    int three_size = 10;
    int answers_size = answers.size();
    
    for(int i =0 ;i<answers_size ; i++ ){
       
        if(one[i%one_size]==answers[i])
            cnt[0].first++;
        if(two[i%two_size]==answers[i])
            cnt[1].first++;
        if(three[i%three_size]==answers[i])
            cnt[2].first++;
           
    }
    sort(cnt.begin(),cnt.end(),cmp);
    int max_n = cnt[0].first;
    for(auto c :cnt){
        if(c.first==max_n)
            answer.push_back(c.second);
      
    }
        
    return answer;
}