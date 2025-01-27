#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1000
//6:43
//dfs
// dfs를 다 해서 -> 경로 찾음 -> 이게 가능한 경로인지 확인
// 방향이 안맞으면 한번 더 들리면 갈 수 있음 -> 비용 추가
vector<vector<pair<int,bool>>> link(MAX+1, vector<pair<int,bool>>(MAX+1));
int des;
bool visit[MAX+1];
set<int>s;
void dfs(int node,int cost){
    
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
   
    des= end;
    for(auto t : traps)
        s.insert(t);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++ ){
            link[i][j] ={3001,0};
        }
         
    }
    for(int i=0;i<roads.size();i++){
        int a = roads[i][0];
        int b = roads[i][1];
        int c = roads[i][2];
        cout<<link[a][b].first<<endl;
        if(link[a][b].first>c){
            link[a][b] = {c,1}; //활성화 된 길
            link[b][a] = {c,0};          
        }        
    }
    
     for(int i=0;i<10;i++){
        for(int j=0;j<10;j++ ){
            cout<<link[i][j].first<<" ";
        }
         cout<<endl;
    }
    
    return answer;
}