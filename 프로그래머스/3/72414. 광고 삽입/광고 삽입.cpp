#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
//누적합
//스트링
//	359999
//cout<<99*60*60 + 59*60 + 59;

long long ad[470000];

//시간 -> 숫자
long long toSeconds(string s){
    int sum=0;
    
    string time = s.substr(0,2);
    string m = s.substr(3,2);
    string sec = s.substr(6,2);
  
    return stoi(time)*60*60 + stoi(m)*60 + stoi(sec);
}
string secondsToS(int seconds){
    string t = to_string(seconds/60/60);
    seconds = seconds - stoi(t)*60*60;
    string m = to_string(seconds/60);
    string s = to_string(seconds%60);
    if(t.size()==1)
        t = "0"+t;
    if(m.size()==1)
        m = "0"+m;
    if(s.size()==1)
        s = "0"+s;
    
    return t+":"+m+":"+s;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
 
    int range=0;
    range = toSeconds(play_time);
    //시청 시간 앞, 뒤 표시
    for(int i=0;i<logs.size();i++){
        
        int stT = toSeconds(logs[i].substr(0,8));
        int endT = toSeconds(logs[i].substr(9));
        
        ad[stT]++;
        ad[endT]--;
       
    }
    
    //한번에 누적합 계산
    for(int i=1;i<=range;i++){
        ad[i] +=ad[i-1];
       
    }
   // cout<<ad[5459]<<endl;
    long long adT = toSeconds(adv_time);
   // adT++;
    
    //최댓값 구하기
    int idx1 =0;
    int idx2=0;
    long long ans=0;
    long long sumT=0;//ad[0];
    int adStartT =0;

    while(idx2<=range && idx1<=idx2){
              
         sumT+=ad[idx2];
         idx2++;
        
        if(sumT>ans){
            adStartT = idx1;
            ans = sumT;
        }
         if(idx2-idx1==adT){
            sumT-=ad[idx1];
            idx1++;
            continue;
        }
        
    }
    
   
    answer = secondsToS(adStartT);
    return answer;
}