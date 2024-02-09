#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<bool>>visit(101,vector<bool>(101,false));
vector<vector<bool>>map(101,vector<bool>(101,false));
vector<vector<int>>dist(101,vector<int>(101,false));


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<rectangle.size();k++){
                //내부에 있으면 false continue;
                if(i>rectangle[k][1]*2 && i<rectangle[k][3]*2 && j>rectangle[k][0]*2 &&j<rectangle[k][2]*2)
                {
                    map[i][j]=false;
                    break;
                }
                // 아웃라인 체크
                if(i==rectangle[k][1]*2 || i==rectangle[k][3]*2 )
                    if(j>=rectangle[k][0]*2 && j<=rectangle[k][2]*2)
                    {
                        map[i][j]=true;
                        continue;
                    }
                if(j==rectangle[k][0]*2 || j==rectangle[k][2]*2 )
                    if(i>=rectangle[k][1]*2 &&i<=rectangle[k][3]*2)
                    {
                        map[i][j]=true;
                        continue;
                    }
            }
        }
    }

    queue<pair<int,int>>q;
    q.push({characterY*2,  characterX*2});
    int dy[] = {0,1,0,-1};
    int dx[] = {1,0,-1,0};
    while(!q.empty()){
        int y = q.front().first;
        int x= q.front().second;
        q.pop();
        visit[y][x]=true;
        if(y== itemY*2 && x==itemX*2){
            answer= dist[y][x]/2;
            break;
        }
        
        for(int i=0;i<4;i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if(next_y<0 || next_y>100 || next_x<0  ||next_x>100)
                continue;
            if(visit[next_y][next_x])
                continue;
            if(map[next_y][next_x]){
                visit[next_y][next_x]=true;
                q.push({next_y,next_x});
                dist[next_y][next_x]=dist[y][x]+1;
            }
        }
        
    }
    
    return answer;
}