#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

int T;
int V,E,D; //노드 간선 목적지
int s,g,h; //시작지, 꼭 거쳐야 하는 곳

vector<pair<int,int>>edges[50001];
set<int>destination;
set<int>destination_tmp;
int dist[2001];
bool visited[2001][2];  // 노드별로 g-h 통과여부에 따른 방문체크 추가
vector<int>answer;

void dijkstra(int start){
    priority_queue<pair<int,pair<int,int>>>pq; //{-경로 비용, {지난 s,h 개수, 노드번호}}
    
    pq.push({0,{0,start}});
    dist[start] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cnt = pq.top().second.first;
        int cur = pq.top().second.second;
       
        pq.pop();

        // 해당 상태를 이미 방문했으면 스킵
        if(visited[cur][cnt]) continue;
        visited[cur][cnt] = true;

        if(dist[cur]<cost)
            continue;
        if(destination.find(cur)!=destination.end() && cnt==1)
            answer.push_back(cur);
        
        for(int i=0;i<edges[cur].size();i++){
            int nxt = edges[cur][i].first;
            int add_cost = edges[cur][i].second;
            int total_cost = add_cost + cost;

            int nxt_cnt = cnt;
            if((cur==g && nxt==h) || (cur==h && nxt==g)){
                nxt_cnt = 1;
            }
            
            // visited 체크 추가
            if(dist[nxt]>=total_cost && !visited[nxt][nxt_cnt]){
                dist[nxt] = total_cost;
                pq.push({-total_cost,{nxt_cnt,nxt}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;

    int a=0,b=0,c=0,k=0;
    while(T--){
        //초기화
        fill(dist,dist+2001,1000000000);
        fill(&visited[0][0], &visited[2000][2], false);  // visited 배열 초기화 추가
        
        cin>>V>>E>>D;
        cin>>s>>g>>h;
        for(int i=0;i<E;i++){
            cin>>a>>b>>c;
            edges[a].push_back({b,c});
            edges[b].push_back({a,c});
        }
        for(int i=0;i<D;i++){
            cin>>k;
            destination.insert(k);
        }
       
        dijkstra(s);
        //정답
        sort(answer.begin(),answer.end());
        for(auto ans :answer)
            cout<<ans<<' ';
        cout<<endl;

        //초기화
        fill(begin(edges), end(edges), vector<pair<int, int>>());
        destination = destination_tmp;
        answer.clear();
    }
   
    return 0;
}