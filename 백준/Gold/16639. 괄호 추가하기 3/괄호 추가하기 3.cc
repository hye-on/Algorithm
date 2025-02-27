#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


int n;
string s;

int dp_min[20][20];
int dp_max[20][20];

int cal(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else return a * b;
}
int main() {

    
    cin>>n;
    cin>>s;
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp_min[i][j] = INT_MAX;
            dp_max[i][j] = INT_MIN;
        }
    }


    for(int i=0;i<n;i+=2){
        dp_max[i][i] = dp_min[i][i] = s[i]-'0';
    }

    for(int len = 2;len<n;len+=2){ //길이
        for(int i=0;i+len<n;i+=2){ // 시작위치
            int end_idx = i + len; //3+8 일때 i=0, end_idx =2;
            for(int k=i+1;k<end_idx;k+=2){ // 기준으로 할 연산자를 가르킴
                int result_cal[] ={
                cal(dp_min[i][k-1],dp_min[k+1][end_idx],s[k]),
                cal(dp_min[i][k-1],dp_max[k+1][end_idx],s[k]),
                cal(dp_max[i][k-1],dp_min[k+1][end_idx],s[k]),
                cal(dp_max[i][k-1],dp_max[k+1][end_idx],s[k])
                };        
                sort(result_cal,result_cal+4);
                dp_min[i][end_idx] = min(dp_min[i][end_idx],result_cal[0]);
                dp_max[i][end_idx] = max(dp_max[i][end_idx],result_cal[3]);
            }
            
            
        }     
        
    }

    cout<<dp_max[0][n-1]<<endl;

    
    return 0;
}