#include <iostream>
#include<queue>
using namespace std;
string s;
char map[20][11][11];
//8초 되에는 다 빈 공간

int noW=8;
void makeMap(int idx){
    for(int i=1;i<=9;i++){
        map[idx][1][i] = '.';
    }
    bool isNo=false;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=8;j++){
            map[idx][i+1][j] = map[idx-1][i][j];
            if(map[idx][i+1][j]=='#')
                isNo = true;
        }
    }

    if(!isNo)
        noW = min(idx,noW);
}
//가만히 있기
int dy[] = {0,1,0,-1,-1,1,1,-1,0};
int dx[] = {1,0,-1,0,-1,1,-1,1,0};
int answer=0;
void bfs(){
    //시간초과 나면 deque로 바꾸기
    queue<pair<pair<int,int>,int>>q;
    q.push({{8,1},0});

    while(!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int time = q.front().second;
        //cout<<curY<<"  "<<curX<<endl;
        q.pop();

      
        if(curY==1 && curX==8 && time>=noW){
            answer=1;
            break;
        }
        
        //1초 동안 욱제의 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다.
        for(int i=0;i<9;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            
            if(ny>8 || ny<1 || nx>8 ||nx<1)
                continue;
            if(map[time][ny][nx]=='#' || map[time+1][ny][nx]=='#')
                continue;
            q.push({{ny,nx},time+1});
        }
        
    }
}
int main() {
    for(int i=1;i<=8;i++){
        cin>>s;
       
        for(int j=0;j<8;j++){
            map[0][i][j+1] = s[j];
           
        }
    }

    for(int i=1;i<=9;i++)
        makeMap(i);
    
    // for(int k=0;k<=9;k++){
    //     for(int i=1;i<=8;i++){
    //         for(int j=1;j<=8;j++){
    //             cout<<map[k][i][j];
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }  

    bfs();
    cout<<answer<<endl;
    return 0;
}