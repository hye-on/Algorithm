#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 5:28
#define MAX 1000000000

vector<int>edges[100001];
bool visit[100001];
int node[100001];
int n,root;
int l,q;


int minimax(int cur,bool flag){ 
    if(node[cur]==MAX+1){
        
    if(flag) //최댓값 구해야 함
        node[cur] = -1;
    else
        node[cur] = MAX+1;//최솟값 구해야 함
        
    }
    visit[cur] = true;
    for(auto nxt:edges[cur]){
        //방문했으면
        if(visit[nxt])
            continue;
        
        if(flag){
            node[cur] = max(node[cur],minimax(nxt,false));
        }else{
            node[cur] = min(node[cur],minimax(nxt,true));
        }
    }
    return node[cur];
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>root;
    int u=0,v=0;
    
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        
    }
    cin>>l;
    int k=0,t=0;

    fill(node,node+100001,MAX+1);
    for(int i=0;i<l;i++){
        cin>>k>>t;
        node[k] =t;
        //visit
    }
    cin>>q;
    int qq=0;

    minimax(root,true);
    
    for(int i=0;i<q;i++){
        cin>>qq;
        cout<<node[qq]<<'\n';
    }

    return 0;
}