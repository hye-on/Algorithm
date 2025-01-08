#include <iostream>
#include <vector>
#include<cstring>
#include <tuple>
#include <algorithm>


using namespace std;

#define INF 2100000000
int tc;
int n,m,w;
int s,e,t;

int dist[501];


void bellman_ford( vector<tuple<int,int,int>>&link){
    string answer ="NO";
    fill(dist,dist+501,INF);

    dist[1] =0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<link.size();j++){
           auto [s, e, c] = link[j]; //c++ 17이상
            if(dist[e]>dist[s]+c){
                dist[e] =dist[s]+c;

                if(i==n){
                    answer="YES";
                    
                }
            }
        }
    }

    cout<<answer<<"\n";
}

int main() {
    cin>>tc;
    while(tc--){
        vector<tuple<int,int,int>>link;
        
        cin>>n>>m>>w;

        for(int i=0;i<m;i++){
              cin>>s>>e>>t;
            link.push_back({s,e,t});
            link.push_back({e,s,t});
        }

        for(int i=0;i<w;i++){
            cin>>s>>e>>t;
            link.push_back({s,e,-t});
        }

        bellman_ford(link);
    }
    return 0;
}