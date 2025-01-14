#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

#define INF 2000000000
//1:55
//bfs, 완탐 , 방문 여부는 map으로

string pTos(vector<vector<int>>&p){
    string ret="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ret+=to_string(p[i][j]);
        }
    }
    return ret;
}


vector<vector<int>>p(3,vector<int>(3,0));
map<string,bool>visit;

queue<pair<pair<int,int>,pair<string,int>>>q; //y,x, 배열 상태, 이동 횟수
int answer=INF;
string answerMap="123456780";

bool OOB(int y,int x){
    if(y>=3 || y<0 || x>=3 ||x<0)
        return true;
    return false;
}
void bfs(){

    int dy[] = {0,1,0,-1};
    int dx[] = {1,0,-1,0};
    
    while(!q.empty()){
       
        int curY = q.front().first.first;
        int curX = q.front().first.second;

        string curMap = q.front().second.first;
        int dist = q.front().second.second;
        q.pop();
        
        if(curMap == answerMap){
            answer = dist;
            break;
        }

        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
           
            if(OOB(ny,nx))
                continue;
           
            //1차원 좌표로 바꾸기
            int cur_pos = curY*3 + curX;
            int n_pos = ny*3 + nx;

            //이동하기
            string t = curMap;
            t[cur_pos] =t[n_pos];
            t[n_pos] = '0';
         
            
            //이미 방문한 적이 있으면
            if(visit.find(t)!=visit.end())
                continue;
             visit[t]=true;
            q.push({{ny,nx},{t,dist+1}});
            
        }
    }
}

int main() {

    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>p[i][j];
            if(p[i][j]==0){
                q.push({{i,j},{"",0}});
            }
        }
    }
    q.front().second.first = pTos(p);
    bfs();
    
    if(answer==INF)
        answer=-1;
    cout<<answer;
    
    return 0;
}