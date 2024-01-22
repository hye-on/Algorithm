#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;
string number;
vector<bool>chk;
vector<bool> p_num;
set<int> make_n;
void dfs(int index, string s){
    if(index>0){
        if(!p_num[stoi(s)]){
            make_n.insert(stoi(s));
        }
           
    }
    for(int i =0 ;i<number.size();i++){
        if(chk[i])
            continue;
        chk[i]=true;
        dfs(index+1, s+number[i]);
        chk[i]=false;
 
    }
}

int solution(string numbers) {

    int size = numbers.size();
    int range = pow(10,size);
    int answer=0;
    number=numbers;
    //소수가 나올수있는 범위구하기 2자리수면 99까지 나올수 있으니까 100이하로 소수다 구하기
    
    chk.resize(numbers.size());
    p_num.resize(range);
    
    p_num[0]=true;
    p_num[1]=true;
    
   for(int i=2;i<range;i++){
      if(p_num[i])
          continue;
       for(int j=i+i;j<range;j+=i){
           p_num[j]=true;
       }    
   }
   
   dfs(0,"");
    
    return answer = make_n.size();
}