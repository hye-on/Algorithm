#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<queue>
using namespace std;

queue<int>q;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int size = A.size();
    int temp=0;
    bool pos = false;
    for(int i=0;i<size;i++){
        if(B[i]>A[i])
            answer++;
        else{
            
            
            for(int j=0;j<q.size();j++){
                if(q.front()>A[i]){
                    answer++;
                    q.pop();
                    pos=false;
                    break;

                }
            }
               
            
            q.push(B[i]);
            
        }
    }
    return answer;
}