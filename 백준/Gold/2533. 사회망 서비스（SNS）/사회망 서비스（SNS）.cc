#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000001
//10:31
//top-down트리 dp?
int n;
vector<vector<int>>edges;
vector<vector<int>>dp;

int findEarlyAdaptor(int cur,int flag,int parent){

    
    //내가 얼리어답터면 연결된 애들 다 얼러 어답터 거나 아니거나
    //내가 얼리어답터가 아니면 연결된 애들 다 얼리 어답터
    if(dp[cur][flag]!=MAX)
        return dp[cur][flag];
    
    int ret=flag;
    //내가 얼리 어답터
    for(auto nxt : edges[cur]){
        if(nxt==parent)
            continue;
        if(flag)
            ret += min(findEarlyAdaptor(nxt,1,cur),findEarlyAdaptor(nxt,0,cur));
        else
            ret += findEarlyAdaptor(nxt,1,cur);
            
    }
     
    return dp[cur][flag] = ret;
}

int main() {
    cin>>n;
    edges.resize(n+1);
    dp.resize(n+1,vector<int>(2,MAX));
        
    int inputA=0,inputB=0;
    
    for(int i=0;i<n-1;i++){
        cin>>inputA>>inputB;
        edges[inputA].push_back(inputB);
        edges[inputB].push_back(inputA);
    }

    findEarlyAdaptor(1,1,0);
    findEarlyAdaptor(1,0,0);
    
    cout<<min(dp[1][0],dp[1][1])<<endl;

    
    
    return 0;
}