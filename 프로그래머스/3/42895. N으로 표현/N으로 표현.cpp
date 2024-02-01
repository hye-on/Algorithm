#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> dp;
int solution(int N, int number) {
    int answer = 0;
    dp.resize(32001);
   
 
    for(int i=1;i<32001;i++){
        if(N==1)
            dp[i]=i;
        else
            dp[i]=2*i;
    }
    
    int j=1;
    int index=N;
    while(index<32001){
        dp[index] = j;
        index= index * 10 +N;
        j++;
       
    }
    
   
  int p =3; 
  while(p--){  
    for(int i=1;i<=32001/2;i++){
        //곱하기
        for(int j=1;j<=i;j++){
            if(i%j==0){
               int k = i/j; 
                dp[i]=min(dp[i],dp[j]+dp[k]);
            }
            
        }
        //나누기
        for(int j=1;i*j<=32001/2;j++){
            dp[i] = min(dp[i],dp[i*j]+dp[j]);
        } 
        
        
        //더하기
        for(int j=1;j<=i;j++){
            dp[i] = min(dp[i],dp[i-j]+dp[j]);
        }   
           
        //빼기
        for(int j=1;j<=i;j++){
            dp[i] = min(dp[i],dp[i+j]+dp[j]);
        }
       
        
    }
  }
    
    if(dp[number]>8)
        answer=-1;
    else
        answer= dp[number];
   
    return answer;
}