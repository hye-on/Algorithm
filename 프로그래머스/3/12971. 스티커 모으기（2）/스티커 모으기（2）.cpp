#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int dp1[100002];
int dp2[100002];

int solution(vector<int> sticker)
{
    int answer =0;
    int size = sticker.size();
    if(size==1)
        return sticker[0];
    dp1[0] =sticker[0]; //맨 앞에 뜯음
    dp1[1] =sticker[0];
    dp2[0] =0;//맨 앞에 안뜯음
    dp2[1] =sticker[1];
    //dp2[2]  = sticker[1];
    
    for(int i=2;i<size-1;i++){
       
       dp1[i] =max(dp1[i-2]+sticker[i],dp1[i-1]);
   }
    
    for(int i= 2;i<size;i++){
        dp2[i] =max(dp2[i-2]+sticker[i],dp2[i-1]);
    }
    
    
    dp1[size-1]=dp1[size-2];
    answer = max(dp1[size-1],dp2[size-1]);
    
    return answer;
}