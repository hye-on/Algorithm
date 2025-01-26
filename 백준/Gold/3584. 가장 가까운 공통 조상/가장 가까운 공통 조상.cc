#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//12:58 ~ 1:26
//O(V + E)
//두 노드에서 루트 쪽으로 bfs 
// A가 B의 부모. 순서가 있으므로 항상 위로 탐색할 수 있음


int T;
int N;
int nodeA,nodeB;
int a,b;
vector<int>edges[10001];
vector<char>dist(10001); // A가방문함 
int answer;

void bfs(){
    queue<pair<char,int>>q;
    q.push({'A',nodeA});
    q.push({'B',nodeB});
    
    dist[nodeA] ='A';
    dist[nodeB] ='B';
    
    while(!q.empty()){
        char from_node = q.front().first; //'A'
        int cur_num = q.front().second; // 3
        q.pop();

        
        for(int nxt:edges[cur_num]){
            //이미 다른 노드에서 방문한 적이 있으면 그게 정답
            if(dist[nxt] !=0 && from_node != dist[nxt]){
                answer = nxt;
                return;
            }
            q.push({from_node,nxt});
            dist[nxt] = from_node;
        }
    }
}

int main() {
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N-1;i++){
            cin>>a>>b;
            edges[b].push_back(a);//항상 부모쪽으로 탐색해야함
        }
        cin>>nodeA>>nodeB;
        //bfs 
        bfs();
        cout<<answer<<'\n';
        
        //초기화
        fill(dist.begin(), dist.end(), 0); //빠트림
        for(int i=1;i<=N;i++)
            edges[i].clear();
    }
   
    return 0;
}