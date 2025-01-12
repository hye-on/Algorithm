#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//2:14
// 순차적으로 간산을 삭제해서 연결된 각 노드 2개로 bfs
//정점번호 +  간선 번호 출력
int n,m;
vector<int>tree[100002];
vector<int> treeEdges[100002];
vector<pair<int,int>>edges[100002]; // {노드 번호, 간선 번호}
int nodeNum[100002];

int treeNum;
int leafNode;
void bfs(int start,int treeNum){

    queue<int>q;
   
    q.push({start});
    nodeNum[start]=treeNum;
    while(!q.empty()){
        int node = q.front();
        leafNode=node;
        q.pop();
        tree[treeNum].push_back(node);
        
        for(int i=0;i<edges[node].size();i++){
            int nxt = edges[node][i].first;
            int edNum = edges[node][i].second;
            if(nodeNum[nxt]==0){
                treeEdges[treeNum].push_back(edNum);
                nodeNum[nxt]=treeNum;
                q.push(nxt);
            }
        }
        
    }
}

int main() {
    cin>>n>>m;
    int a=0,b=0;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        edges[a].push_back({b,i});
        edges[b].push_back({a,i});
       
    }
    //트리 개수 구하기

    for(int i=1;i<=n;i++){
        if(nodeNum[i]==0){
            treeNum++; //1,2,3
            bfs(i,treeNum);
            
        }
            
    }

   if(treeNum>=3){
       cout<<-1;
      return 0;
   }
    
    if(treeNum==1){
      tree[1].clear();
      treeEdges[1].clear();

     fill(nodeNum,nodeNum+100001,0);
        
     nodeNum[leafNode]=2;
    int startN =1;
     if(edges[leafNode].size()>0)   
         startN= edges[leafNode][0].first;
     
    
     tree[2].push_back(leafNode);
     bfs(startN,1);

     
       
    }
    if(tree[1].size()==tree[2].size())
    {   cout<<-1;
    }else{
    
    //트리 개수
    cout<<tree[1].size()<<' '<<tree[2].size()<<'\n';
    //노드 번호
   // sort(tree[1].begin(), tree[1].end());
    
    for(auto t :tree[1])
        cout<<t<<' ';
    cout<<endl;
    //간선 번호
   // sort(treeEdges[1].begin(), treeEdges[1].end());
    for(auto e:treeEdges[1])
        cout<<e<<' ';
    cout<<endl;
    //노드 번호
  //  sort(tree[2].begin(), tree[2].end());
    
    for(auto t :tree[2])
        cout<<t<<' ';
    cout<<endl;
    //간선 번호
  //   sort(treeEdges[2].begin(), treeEdges[2].end());   
    for(auto e:treeEdges[2])
        cout<<e<<' ';

    }
    
    
    return 0;
}