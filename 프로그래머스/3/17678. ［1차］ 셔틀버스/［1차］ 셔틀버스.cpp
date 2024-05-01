#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a (string s){
    int tt = (s[4]-'0')*1 + (s[3]-'0')*10 + (s[1]-'0')*60 + (s[0]-'0')*60*10;
    return tt;
}

string b(int a){
    string ss ="";
    ss = to_string(a/60) + ":" ;//+ to_string(a%60);
    if(to_string(a/60).size()==1)
        ss="0"+to_string(a/60) + ":";
    if(to_string(a%60).size()==1)
        ss=ss+"0"+to_string(a%60);
    else
        ss=ss+to_string(a%60);
    return ss;
}
string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(),timetable.end());
    
    string answer;
    if(timetable.size()<m)
        answer="09:00";
    else
        answer = b(a(timetable[0])-1);
    if(a(answer)<0)
        answer="00:00";
 
    string st= "09:00";
    int cnt=0;
    int idx=0;
    
    for(int i=0;i<n;i++){
        while(true){
            if(idx>=timetable.size()){
                if(cnt==m)
                    answer = answer = b(a(timetable[idx-1])-1);
                else
                    answer= st;
                break;
            }
                
            //시간보다 작고, m보다 작으면 탐
            if(timetable[idx]<=st && cnt<m){
               
                idx++;
                cnt++;
                continue;
            }
            //시간이 크면 탈출, m이 크면 탈출 -> 다음 차 탐 , answer갱신
            if(timetable[idx]>st || cnt == m){
                if(timetable[idx]>st && cnt < m){ 
                    answer = st;
                    
                }
                if(timetable[idx]<=st &&  cnt == m){
                    
                    answer = b(a(timetable[idx-1])-1);
                    
                }
                cnt=0;
                break;
            }
            //크루가 끝이면 탈출 answer= st
        }
        st = b(a(st)+t);
    }
  
    if(answer>"23:59")
        answer="23:59";
   
    return answer;
}