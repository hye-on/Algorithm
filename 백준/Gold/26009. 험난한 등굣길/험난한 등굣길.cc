#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//120억 개를 마크해야해서 시간초과
//테두리만 마크하자
//9:00
int map[3001][3001];
int range[3001][3001];
int n,m;
int k;
int answer=-1;

void mark(int y,int x,int d){
    int dy[] ={-1,1,1,-1};
    int dx[] ={1,1,-1,-1};
    vector<pair<int,int>>pos = {{y,x-d},{y-d,x},{y,x+d},{y+d,x}};

 
    for(int i=0;i<4;i++){
    
        int curY = pos[i].first;
        int curX = pos[i].second;
     
        for(int j=0;j<=d;j++){
            if(!(curY>n || curY<=0 || curX>m || curX<=0))
               map[curY][curX]=1;
            curY+=dy[i];
            curX+=dx[i];
        }
    }
   
}

void bfs(){

    int dy[] ={0,1,0,-1};
    int dx[] = {1,0,-1,0};
    
    queue<pair<pair<int,int>,int>>q;
    q.push({{1,1},0});
    map[1][1]=1;
    while(!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if(curY==n && curX == m){
            answer = d;
            break;
        }
        for(int i=0;i<4;i++){
            int ny = curY +dy[i];
            int nx = curX +dx[i];

            if(ny>n || ny<=0 || nx>m || nx<=0)
                continue;

            if(map[ny][nx]==1)
                continue;
            map[ny][nx]=1;
            q.push({{ny,nx},d+1});
        }
    }
}
int main() {
    cin>>n>>m;
    cin>>k;

    int y=0,x=0,d=0;

    fill(range[0],range[3001],-1);
    for(int i=0;i<k;i++){
        cin>>y>>x>>d;
        range[y][x]  = max(range[y][x],d);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(range[i][j]>=0){    
                mark(i,j,range[i][j]);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<map[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    bfs();
    

    if(answer==-1)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<answer;
            
    }
    return 0;
}