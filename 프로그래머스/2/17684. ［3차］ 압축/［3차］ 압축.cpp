#include <string>
#include <vector>
#include<map>
#include<iostream>

using namespace std;

map<string,int>dir;

// memo : char to string
// map.find()
vector<int> solution(string msg) {
    vector<int> answer;
    //사전 1~26 초기화
    
    for(int i=1;i<27;i++){
        char c = 'A' + i-1;
       dir.insert({string(1,c),i});
        
        
    }
   
    //roop
    //사전 등록되었는지 확인 . 없을 때까지
    // 출력, w+c 등록
    //다음 루프
    int size = msg.size();
    string tmp="";
    int ans_n=0;
    int idx=27;
    for(int i=0;i<size;i++){
        tmp="";
        for(int j=i;j<size;j++){
            tmp+=msg[j];
            
            if(dir.find(tmp)==dir.end()){//존재안하면 
                answer.push_back(ans_n);
                dir[tmp]=idx;
                idx++;
                i=j-1;
                break;
            }else{
                ans_n = dir[tmp];
            }
            if(j==size-1){
                answer.push_back(ans_n);
                return answer;
            }
        }
        
    }
  
    
    return answer;
}