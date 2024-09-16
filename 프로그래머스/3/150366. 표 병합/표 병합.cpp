#include <string>
#include <vector>
#include <iostream>
using namespace std;
//11:23 ~ 

// 구현?
// 위치 가지고 있는 배열 a , 값 가지고 있는 배열 b
//update - b 값 삽입
//update - b 값 교체
//Merge - a의 위치의 point와 일치하는 모든 셀들 합침, 아무거나 상관없음. 
//       - 값은 a를 참고해서 r1,c1것으로 다 b에 넣어줌 비어 있으면 r2,c2꺼 
// a에서 r,c에 있는 point에 있는 값과 일치하는거 다 해제. 값있으면 r,c에만 넣어줌

pair<int,int> p[51][51];
string map[51][51];

void update(string cmd){
    int idx = cmd.find(' ');
    string t = cmd.substr(idx);
}  

void merge(string cmd){
    
}
void un_merge(string cmd){
    
}

void print(string cmd){
    
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i=0;i<commands.size();i++){
        string cmd = commands[i].substr(0,commands[i].find(' ')+1);
        cout<<cmd<<endl;
        if(cmd=="UPDATE"){
            cout<<"???"<<endl;
            update(commands[i]);
        }else if(cmd=="MERGE"){
            merge(commands[i]);
        }else if(cmd=="UPMERGE"){
            un_merge(commands[i]);
        }else{
            print(commands[i]);
        }
    }
    return answer;
}