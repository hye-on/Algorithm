#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
//11:23 ~ 1:04 분

// 구현?
// 위치 가지고 있는 배열 a , 값 가지고 있는 배열 b
//update - b 값 삽입
//update - b 값 교체
//Merge - r2,c2에 다 r1,c1을 넣어줌
//       - 값은 a를 참고해서 r1,c1것으로 다 b에 넣어줌 비어 있으면 r2,c2꺼 
//Unmerge - a에서 r,c에 있는 point에 있는 값과 일치하는거 다 해제. 값있으면 r,c에만 넣어줌

pair<string,string> p[51][51];
string map[51][51];

vector<string> token;
string word;

void update(string cmd){
    int idx = cmd.find(' ');
    string t = cmd.substr(idx+1);
    vector<string> tokens = token;
    stringstream ss(t);
    // 입력을 공백으로 분리
    while (ss >> word) {
        tokens.push_back(word);
    }
    //cout<<t<<" "<<tokens.size()<<endl;
    if(tokens.size()==3){//숫자면1번 업데이트 //문자인데 숫자로 시작될수도 있음
        string y = t.substr(0,t.find(' '));
        t = t.substr(y.size()+1);
        string x =  t.substr(0,t.find(' '));
        t = t.substr(x.size()+1); //오타때문에 계속 실패함 ㅠㅜ
        //y,x에 넣기
        string yy = p[stoi(y)][stoi(x)].first;
        string xx = p[stoi(y)][stoi(x)].second;
      
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(p[i][j].first==yy &&p[i][j].second==xx)
                    map[i][j] =t;
                }
            }
    }else{
        string v1 = t.substr(0,t.find(' '));
        t = t.substr(v1.size()+1);
        string v2 =  t.substr(0,t.find(' '));
        
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                    if(map[i][j]==v1){
                        map[i][j] =v2;
                    }
                }
            }
        
    }
}  

void merge(string cmd){
    int idx = cmd.find(' ');
    string t = cmd.substr(idx+1);
    
    string r1 = t.substr(0,t.find(' '));
    t = t.substr(r1.size()+1);
    string c1 =  t.substr(0,t.find(' '));
    t = t.substr(c1.size()+1);
    string r2 = t.substr(0,t.find(' '));
    t = t.substr(r2.size()+1);
    string c2 =  t.substr(0,t.find(' '));
   // cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    string value = map[stoi(r1)][stoi(c1)];
    if(value.size()==0)
        value = map[stoi(r2)][stoi(c2)];
    
    string r11 = p[stoi(r1)][stoi(c1)].first;
    string c11 = p[stoi(r1)][stoi(c1)].second;
    
    string r22 = p[stoi(r2)][stoi(c2)].first;
    string c22 = p[stoi(r2)][stoi(c2)].second;

    //위치 병합
      for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(p[i][j].first==r22 &&p[i][j].second==c22){
                    p[i][j] = {r11,c11};
                    map[i][j] = value;
                }
                if(p[i][j].first==r11 &&p[i][j].second==c11){
                    map[i][j] = value;
                }
            }   
        }
    
}
void un_merge(string cmd){
    int idx = cmd.find(' ');
    string t = cmd.substr(idx+1);
    
    string r = t.substr(0,t.find(' '));
    t = t.substr(r.size()+1);
    string c =  t.substr(0,t.find(' '));
    string value = map[stoi(r)][stoi(c)];
    
    string r11 = p[stoi(r)][stoi(c)].first;
    string c11 = p[stoi(r)][stoi(c)].second;
    for(int i=1;i<=50;i++){
        for(int j=1;j<=50;j++){
            if(p[i][j].first==r11 &&p[i][j].second==c11){
                p[i][j] = {to_string(i),to_string(j)};
                map[i][j] ="";
            }
            if(i== stoi(r) && j == stoi(c))
                map[i][j] = value;
        }   
    }
    
    
}

string print(string cmd){
    int idx = cmd.find(' ');
    string t = cmd.substr(idx+1);
    string r = t.substr(0,t.find(' '));
    t = t.substr(r.size()+1);
    string c =  t.substr(0,t.find(' '));
    return map[stoi(r)][stoi(c)];
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    //초기화
    
    for(int i=1;i<=50;i++){
        for(int j=1;j<=50;j++){
            p[i][j] = {to_string(i),to_string(j)};
        }
    }
    for(int i=0;i<commands.size();i++){
        string cmd = commands[i].substr(0,commands[i].find(' '));
        if(cmd=="UPDATE"){
            update(commands[i]);
            
        }else if(cmd=="MERGE"){
            merge(commands[i]);


        }else if(cmd=="UNMERGE"){
            un_merge(commands[i]);
        }else{
            if(print(commands[i]).size()==0)
                answer.push_back("EMPTY");
            else
                answer.push_back(print(commands[i]));
        }
    }
    return answer;
}