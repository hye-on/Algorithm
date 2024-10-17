#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


//11:39
vector<vector<char>>puyo(12,vector<char>(6));
bool visit[12][6];
bool isPop;
int h=-1; //높이 구하기
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
bool OOB(int y,int x){
    if(y>=12 || y<0 || x>=6 || x<0)
        return true;
    return false;
}
//bfs
bool playPuyo(int y,int x,char Color){
    queue<pair<int,int>>q;
    q.push({y,x});
    visit[y][x] = true;
    int cnt=0;
   
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
       
        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(OOB(ny,nx))
                continue;
            if(!visit[ny][nx] && puyo[ny][nx]==Color){
                q.push({ny,nx});
                visit[ny][nx] = true;
                cnt++;
            }
        }
    }
  //  cout<<y<<"  "<<x<<"  "<<cnt<<endl;
    if(cnt>=3){
        //visit true 인것 .으로 만들기
       
        for(int i=h;i<12;i++){
            for(int j=0;j<6;j++){      
                if(visit[i][j]){
                    puyo[i][j]='.';
                }
            }
        }
        return true;
    }
    else{
        for(int i=h;i<12;i++){
            for(int j=0;j<6;j++){      
                visit[i][j]=false;
            }
        }
        return false;
    }
}
void gravitation(){

    for(int j=0;j<6;j++){
        for(int i = 11;i>=h;i--){
            if(puyo[i][j]!='.'){
                int y = i+1;
                while(y<12 && puyo[y][j]=='.'){
                    puyo[y][j] = puyo[y-1][j];
                    puyo[y-1][j]='.';
                    y++;
                }
            }
        }
    }
}
int main() {
    string tmp="";
   
   
    for(int i=0;i<12;i++){
         cin>>tmp;
        int t=0;
        for(int j=0;j<6;j++){
            puyo[i][j]=tmp[j];
            if(tmp[j]=='.')
                t++;
        }
       
    }
     for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if(puyo[i][j]!='.'){
                h=i;
                break;
            }
        }
         if(h>=0)
             break;
     }


    int answer=0;
    if(h < 0) h = 0;
    while(true){
        for(int i=h;i<12;i++){
            for(int j=0;j<6;j++){
                if(puyo[i][j]!='.' && !visit[i][j]){
                    if(playPuyo(i,j, puyo[i][j])){
                        isPop =true;
                        
                    }
                }
            }
        }
        
        //visit 초기화
        memset(visit,false,sizeof(visit));

        gravitation();
   
        if(isPop)
            answer++;
        else
            break;
    
        isPop=false;
    }

    cout<<answer;
    return 0;
}