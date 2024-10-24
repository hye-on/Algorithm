#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <tuple>
using namespace std;

//1:59
//구현 + bfs
// 한 칸을 여러번 방문할 수 있음. 똑같은 모양으로 방문한 것을 체크

int n;
vector<vector<int>> board;
int answer;

int dx[] ={0,1,0,-1};
int dy[] ={1,0,-1,0};
struct Robot {
    int x1;
    int y1;
    
    int x2;
    int y2;
    
    int dir; // 0이면 가로, 1이면 세로
    
    //찾은 부분
     bool operator<(const Robot &other) const {
        return tie(x1, y1, x2, y2, dir) < tie(other.x1, other.y1, other.x2, other.y2, other.dir);
    }
};
map<Robot,int>m;

bool OOB(int y,int x){
    if(y>=n || y<0 || x>=n || x<0)
        return true;
    if(board[y][x]==1)
        return true;
    return false;
}

bool isVisit(int x1,int y1, int x2,int y2, int d){
    if(m.find({x1,y1,x2,y2,d})==m.end() && (m.find({x2,y2,x1,y1,d})==m.end())){
        return false; //방문한 적 없음
    }

    return true;
}

bool isDes(int x1,int y1, int x2,int y2){
    if(x1==n-1 && y1==n-1)
        return true;
    if(x2==n-1 && y2==n-1)
        return true;
    
    return false;
}

void bfs(){
    queue<pair<Robot,int>>q; //second -cnt
    q.push({{0,0,1,0,0},0});
  //   m[{0,0,1,0,0}]=1;
    while(!q.empty()){
        
        int x1 = q.front().first.x1;
        int y1 = q.front().first.y1;
        
        int x2 = q.front().first.x2;
        int y2 = q.front().first.y2;
        
        int dir = q.front().first.dir;
        
        int cnt = q.front().second;
      
        q.pop();
        if(isVisit(x1,y1,x2,y2,dir))
            continue;
      //    cout<<cnt<<"  "<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<"  "<<dir<<endl;
        m[{x1,y1,x2,y2,dir}]=1;
        if(isDes(x1,y1,x2,y2)){
            answer = cnt;
            break;
        }
        
        //회전 없이 양옆
        for(int i=0;i<4;i++){
            
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            
            if(OOB(ny1,nx1) || OOB(ny2,nx2))
                continue;
        
            if(isVisit(nx1,ny1,nx2,ny2,dir))
                continue;
            
            q.push({{nx1,ny1,nx2,ny2,dir},cnt+1});
            
        }
        
        if(dir==0){//가로
            //y1,x1을 축으로 함
            //1. 위로 올림
            if(!OOB(y1-1,x1) && !OOB(y2-1,x2)){
                int ny = y1-1;
                int nx = x1;
                if(!isVisit(nx,ny,x1,y1,1-dir)){
                    q.push({{nx,ny,x1,y1,1-dir},cnt+1});
                }
            }
            //2. 아래로 내림
             if(!OOB(y1+1,x1) && !OOB(y2+1,x2)){
                int ny = y1+1;
                int nx = x1;
                 
                if(!isVisit(nx,ny,x1,y1,1-dir)){
                    q.push({{nx,ny,x1,y1,1-dir},cnt+1});
                }
            }
            
            //y2,x2를  축으로 함
             //1. 위로 올림
            if(!OOB(y1-1,x1) && !OOB(y2-1,x2)){
                int ny = y2-1;
                int nx = x2;
                if(!isVisit(nx,ny,x2,y2,1-dir)){
                    q.push({{nx,ny,x2,y2,1-dir},cnt+1});
                }
            }
            //2. 아래로 내림
             if(!OOB(y1+1,x1) && !OOB(y2+1,x2)){
                int ny = y2+1;
                int nx = x2;
                 
                if(!isVisit(nx,ny,x2,y2,1-dir)){
                    q.push({{nx,ny,x2,y2,1-dir},cnt+1});
                }
            }
            
        }else{ //세로
            
             //y1,x1을 축으로 함
            //1. 오른쪽으로 회전
            if(!OOB(y1,x1+1) && !OOB(y2,x2+1)){
                int ny = y1;
                int nx = x1+1;
                if(!isVisit(nx,ny,x1,y1,1-dir)){
                    q.push({{nx,ny,x1,y1,1-dir},cnt+1});
                }
            }
            //2. 왼쪽으로 회전
             if(!OOB(y1,x1-1) && !OOB(y2,x2-1)){
                int ny = y1;
                int nx = x1-1;
                 
                if(!isVisit(nx,ny,x1,y1,1-dir)){
                    q.push({{nx,ny,x1,y1,1-dir},cnt+1});
                }
            }
            
            //y2,x2를  축으로 함
             //1. 오른쪽으로 회전
            if(!OOB(y1,x1+1) && !OOB(y2,x2+1)){
                int ny = y2;
                int nx = x2+1;
                if(!isVisit(nx,ny,x2,y2,1-dir)){
                    q.push({{nx,ny,x2,y2,1-dir},cnt+1});
                }
            }
            //2. 왼쪽으로 회전
             if(!OOB(y1,x1-1) && !OOB(y2,x2-1)){
                int ny = y2;
                int nx = x2-1;
                 
                if(!isVisit(nx,ny,x2,y2,1-dir)){
                    q.push({{nx,ny,x2,y2,1-dir},cnt+1});
                }
            }
            
        }
       
        
        
    }
}
int solution(vector<vector<int>> _board) {
    
    board = _board;
    n = board.size();
    
    bfs();
//     Robot a = {0,0,1,0,0};
//     m[a] =2;
    
//    if(m.find({0,0,1,0,0})!=m.end())
//         cout<<"??";
    
    return answer;
}