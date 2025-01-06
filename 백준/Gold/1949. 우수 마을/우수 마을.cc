#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

//5:32 ~ 6:36
//dp + 비트마스킹 - n이 10000이라서 어려울 것 같다.
//i번째 마을을 뻈을 때 총 금액을 저장


int n;
int a,b;
int headCnt[10001];
vector<int>link[10001];
bool visit[10001];


int dp[10001][2]; //i번째 true
void dfs(int node){ 

    visit[node]=true;
    dp[node][0] = 0;
    dp[node][1] = headCnt[node]; 
        
    for(int i=0;i<link[node].size();i++){
        int next = link[node][i];
        if(visit[next])
            continue;
        dfs(next);
        dp[node][0] += max(dp[next][0],dp[next][1]);
        dp[node][1] += dp[next][0];
    }
  
}

int main() {
    cin>>n;

    int totalCnt=0;
    for(int i=1;i<=n;i++){
        cin>>headCnt[i];
        totalCnt+=headCnt[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    
    
    dfs(1);
    int answer = max(dp[1][0],dp[1][1]);
    cout<<answer;
   
}