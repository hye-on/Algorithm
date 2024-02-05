#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>>dp_max(202,vector<int>(202,-10000000));
vector<vector<int>>dp_min(202,vector<int>(202,10000000));
vector<string> arr;

int calculate(int start, int end,int isMax){
    
    if(isMax & (dp_max[start][end] !=-10000000) )
        return dp_max[start][end];
    if(!isMax &(dp_min[start][end]!=10000000 ))
        return dp_min[start][end];
    if(start==end)
        return dp_max[start][end];
    
    for(int i=start+1;i<end;i+=2){
        if(arr[i]=="+"){
            dp_max[start][end] = max(dp_max[start][end],calculate(start,i-1,true) + calculate(i+1,end,true));
            dp_min[start][end] = min(dp_min[start][end],calculate(start,i-1,false) + calculate(i+1,end,false));
        }
        else if(arr[i]=="-"){
           
            dp_max[start][end] = max(dp_max[start][end],calculate(start,i-1,true) - calculate(i+1,end,false));
            dp_min[start][end] = min(dp_min[start][end],calculate(start,i-1,false) - calculate(i+1,end,true));
        }
            
    }
    
   if(isMax)
       return dp_max[start][end];
    else
        return dp_min[start][end];
}
int solution(vector<string> _arr)
{
    int answer=-1;
    arr=_arr;
    for(int i=0;i<arr.size();i+=2){
        dp_max[i][i] = stoi(arr[i]);
        dp_min[i][i] = stoi(arr[i]);
    }
    calculate(0,arr.size()-1,true);
    answer = dp_max[0][arr.size()-1];
    return answer;
}
