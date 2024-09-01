#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cal(int t){
    int cnt =0;
    while(t>0){
        if(t%2==1)
            cnt++;
        t = t/2;       
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
   
    int nCnt = cal(n);
  
    for(int i=n+1;;i++){
        if(cal(i)==nCnt)
        { 
          answer = i;
          break;
        }
    }

    return answer;
}