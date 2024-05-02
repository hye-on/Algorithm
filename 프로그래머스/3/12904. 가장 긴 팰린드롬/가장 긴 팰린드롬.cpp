#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer=1;
    int start=0,end=0;
    for(int i=0;i<s.size();i++){
        if(end-start+1<answer)
            break;
        for(int j=i+1;j<s.size();j++){
            start=i,end=j;
            while(true){
                if(s[start]!=s[end]){
                    
                    break;
                }
                if(start==end || (start+1)==end){
                    answer= max(answer, j-i+1);
                }
                start++;
                end--;
            }
        }
    }

    return answer;
}