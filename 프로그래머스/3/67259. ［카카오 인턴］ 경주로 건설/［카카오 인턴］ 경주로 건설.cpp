#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
//지금까지 비용, 상하-좌우 여부, bfs


//vector<vector<int>>dist(27,vector<int>(27,2000000000));
int dist[4][26][26];
vector<vector<int>> board;
int answer=2000000000;
int s;
void bfs(){
    
    for(int i=0;i<4;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                dist[i][j][k]=200000000;
    
    queue<pair<pair<int,int>,pair<int,int>>>q;//y,x,dir,cost
    q.push({{0,0},{-1,0}});
    int dy[]={0,0,1,-1};
    int dx[]={1,-1,0,0};

    while(!q.empty()){
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int dir = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if(cur_y==s-1&&cur_x==s-1)
        {
            answer= min(answer,cost);
            continue;
        }
        for(int i=0;i<4;i++){
            int y = cur_y+dy[i];
            int x = cur_x +dx[i];
            if(y<0 || y>s-1 || x<0 || x> s-1)
                continue;
            if(board[y][x]==1)
                continue;
            int tmp_cost=0;
            if(dir != i && dir!=-1)
                tmp_cost=cost+600;
            else
                tmp_cost=cost+100;
            
            if(dist[i][y][x]>=tmp_cost){
                dist[i][y][x]=tmp_cost;
                q.push({{y,x},{i,tmp_cost}});
            }
            
        }
        
    }
}

int solution(vector<vector<int>> _board) {
    board=_board;
    s=board.size();
    bfs();
  

    return answer;
}