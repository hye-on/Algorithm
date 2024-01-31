#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> str_num;

bool compare(string a, string b){
   
    return a+b>b+a;
       
  
}
string solution(vector<int> numbers) {
    string answer = "";
   
 
    for(auto n : numbers){
        str_num.push_back(to_string(n));
    }
    sort(str_num.begin(),str_num.end(),compare);
    if(str_num[0]=="0")
        return "0";
    for(int i= 0;i<str_num.size();i++){
        answer+=str_num[i];
    }
   
    return answer;
}