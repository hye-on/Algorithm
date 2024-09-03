#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<string>se;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    char b = words[0][0];
    for(int i=0;i<words.size()/n +1 ;i++){//i+1해야함
        for(int j=n*i;j<n*i+n && j<words.size();j++){ // 012 , 345
            //뒤의 글자랑 앞의 글자랑 같지 않거나 이미 있는 단어라면
           
            if(words[j].size()==1 || b!=words[j][0] || se.find(words[j]) != se.end()){
                 
                answer[0] = j%n+1;
                answer[1]= i+1;
                return answer;
            }
            se.insert(words[j]);
            int idx = words[j].size()-1;
            b = words[j][idx];
        }
       
    }

    return answer;
}