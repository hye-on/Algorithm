#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int sum=0;
    int j=1;
    for(int i=1;i<=n;i++){
        sum+=i;
        if(sum>=n){
            
            while(sum>=n){
                if(sum==n){
                   
                    answer++;
                    break;
                }
                sum-=j;
                j++;
            }
        }
    }
    
    return answer;
}