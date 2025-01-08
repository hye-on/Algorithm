#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

#define INF 2100000000

//5:50
//벨만포드

int n,m;
int a,b,c;
vector<pair<int,int>>link[501];
long long dist[501];
void bellman_ford(){
    fill(dist,dist+501,INF);
    dist[1]=0;

    bool cycle=false;

    for(int k=1;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<link[i].size();j++){
                int next = link[i][j].first;
                int cost = link[i][j].second;
                if(dist[i]!=INF && dist[next]> dist[i]+cost){
                    dist[next] = dist[i]+cost;

                    if(k==n){ //n-1까지가 거리 다 구한것. 더 줄어들면 음의 사이클이 있다는 뜻
                        cycle =true;
                    }
                }
            }
        }
    }

    if(cycle)
        cout<<-1;
    else{
        for(int i=2;i<=n;i++){
            cout<<(dist[i]!=INF? dist[i]:-1)<<"\n";
        }
    }
}

int main() {

    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        link[a].push_back({b,c});
    }

    bellman_ford();
    
    return 0;
}