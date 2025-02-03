#include <bits/stdc++.h>

using namespace std;


//루트에서 dfs해서 트리에 하위 노드 개수 적어주기

//O(100000 log100000)
//10:50

int n,r,q;
vector<int>edges[100001];
vector<int>node(100001,1);
bool visited[100001];


void dfs(int cur){

    for(auto nxt:edges[cur]){
        if(visited[nxt])
            continue;
        visited[nxt] = true;
        dfs(nxt);     
        node[cur] += node[nxt];
      //  visited[nxt] =false;
       
    }    
    
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>r>>q;
    
    int u=0,v=0;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    visited[r]=true;
    dfs(r);

    int query=0;
    for(int i=0;i<q;i++){
        cin>>query;
    
        cout<<node[query]<<'\n';
    }

  
    
    
    return 0;
}