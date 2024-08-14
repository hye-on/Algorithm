#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;
char map[101][101];
//10:52
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int n,m;
int bfs(int y, int x){
    int sum=0;
    queue<pair<int,int>>q;
    q.push({y,x});
    sum+=map[y][x]-'0';
    map[y][x]='X';
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny>=n || ny<0 || nx>=m || nx<0)
                continue;
            if(map[ny][nx]=='X')
                continue;
            q.push({ny,nx});
            sum+=(map[ny][nx]-'0');   
            map[ny][nx]='X';
        }
    }
    return sum;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]=maps[i][j];
        }
    }
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(map[i][j]!='X')
                answer.push_back(bfs(i,j));
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size()==0)
        answer.push_back(-1);
    return answer;
}