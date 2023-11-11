#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<vector<int>> answer;

void hnoi(int n ,int from , int via , int to){
    
   if(n==1)
   {   
       vector<int>temp1;
       temp1.push_back(from);
       temp1.push_back(to);
    
       answer.push_back(temp1);
      
        return;
   }
   hnoi(n-1,from,to,via);
    vector<int>temp2;
    temp2.push_back(from);
    temp2.push_back(to);
    answer.push_back(temp2);
   hnoi(n-1,via,from,to) ;
          
}

vector<vector<int>> solution(int n) {
    hnoi(n,1,2,3);
   return answer;
}