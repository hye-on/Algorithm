#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>

using namespace std;

//5:41
//가중치가 1이상인데 어떻게 가중치가 주어져있지 않는케이스가 있지?

int n;
int cost[10001];
int dp[10001][2]; //값
vector<int>link[10001];
bool visit[10001];
int a,b;



void dfs(int cur){
    

    visit[cur]=true;

    dp[cur][0] =0;
    dp[cur][1] =cost[cur];


    for(int i=0;i<link[cur].size();i++){
        int next = link[cur][i];

        if(visit[next])
            continue;
        dfs(next);

        

        dp[cur][0] +=max(dp[next][1],dp[next][0]); //독립집합에 포함해도 되고 안해도 된다.
        dp[cur][1] += dp[next][0];
    }
    
    
}

vector<int>sNode;


void trace(int cur, bool include) {
    visit[cur] = true;

    if (include) {
        // 현재 노드를 포함하면 자식은 포함하지 않음
        sNode.push_back(cur);
        for (int next : link[cur]) {
            if (!visit[next]) {
                trace(next, false);
            }
        }
    } else {
        // 현재 노드를 포함하지 않으면 자식은 선택 가능
        for (int next : link[cur]) {
            if (!visit[next]) {
                if (dp[next][1] > dp[next][0]) {
                    trace(next, true);
                } else {
                    trace(next, false);
                }
            }
        }
    }
}


int main() {
    
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>cost[i];

    for(int i=0;i<n;i++){
        cin>>a>>b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    dfs(1);
    memset(visit,0,sizeof(visit));
  

    trace(1, dp[1][1] > dp[1][0]);
    

    cout<<max(dp[1][0],dp[1][1])<<'\n';

    sort(sNode.begin(),sNode.end());
    for(int i=0;i<sNode.size();i++)
        cout<<sNode[i]<<' ';

    return 0;
}