#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(vector<int> &a, vector<int> &b){
    if (a[0] - a[1] == b[0] - b[1])
        return a[0] / a[1] > b[0] / b[1];
    else
        return a[0] - a[1] > b[0] - b[1];
}
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    sort(info.begin(),info.end(),cmp);
    
    int a_sum=0,b_sum=0;
    
    for(int i=0;i<info.size();i++){
        
        int a_cost = info[i][0];
        int b_cost = info[i][1];
        
        if(b_cost+b_sum<m)
            b_sum+=b_cost;
        else
            a_sum+=a_cost;
        
        if(a_sum>=n){
            return -1;
        }
        
        
    }
    
    return answer=a_sum;
}