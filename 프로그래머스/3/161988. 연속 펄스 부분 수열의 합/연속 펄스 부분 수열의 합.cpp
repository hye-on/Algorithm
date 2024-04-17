#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
vector<long long>numP;
vector<long long>numM;
long long dpP[500001];
long long dpM[500001];
long long solution(vector<int> sequence) {
    
    long long ansP=0,ansM=0,answer = 0;
    long long sumP=0,sumM =0;
    int size = sequence.size();
    
    if(size==1){
        return answer= max(sequence[0],sequence[0]*-1);
    }
    numP.resize(size);
    numM.resize(size);
   
    int n =1;
    for(int i=0;i<size;i++){
        numP[i] = sequence[i]*n;
        n*=-1;
        numM[i] = sequence[i]*n; ;
     
    }
    dpP[0]=numP[0];
    dpM[0]=numM[0];
    for(int i=1;i<size;i++){
        dpP[i] = max(numP[i],dpP[i-1]+numP[i]);
        ansP = max(dpP[i],ansP);
        
        dpM[i] = max(numM[i],dpM[i-1]+numM[i]);
        ansM = max(dpM[i],ansM);
    }


  
    return answer = max(ansP,ansM);
}