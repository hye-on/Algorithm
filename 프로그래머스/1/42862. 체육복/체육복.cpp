#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool students[33];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i=0;i<reserve.size();i++){
        students[reserve[i]]=true;
    }
    
    sort(lost.begin(),lost.end());
    
    int cnt=0;

  
    for(int i=0;i<lost.size();i++){
      
        if(students[lost[i]]){
            students[lost[i]]=false;
            cnt++;
            continue;
        }
        if(students[lost[i]-1] )
        {   students[lost[i]-1]=false;
            cnt++;
        }
        else if(students[lost[i]+1] ){
            if(i+1<lost.size() && lost[i]+1 ==lost[i+1] && students[lost[i+1]]){
                students[lost[i+1]]=false;
                cnt++;
                lost[i+1]=31;
                continue;
            }
            students[lost[i]+1]=false;
            cnt++;
        }
    }
    return answer=  n - (lost.size()-cnt);
}