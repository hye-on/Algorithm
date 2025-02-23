#include <iostream>
#include <queue>
using namespace std;

// 1~ 9까지 다 bfs하기
// 1 bfs 높이는 주변에 1이 아닌 숫자 중에 최솟값
// 수영장 들어 갈 수 있는 물 크기 구하고 높이로 채우기 
// 2 bfs ...

int n,m;
int map[51][51];
bool visit[51][51];
bool ban_area[51][51];
queue<pair<int,int>>q[10]; //물의 높이 1~9



int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int high;
bool flag;

void bfs(pair<int,int>start,int h){

    queue<pair<int,int>>bq;
    bq.push(start);
    high = 9;
    flag = false;
    while(!bq.empty()){
        int cury = bq.front().first;
        int curx = bq.front().second;
        bq.pop();

        for(int i=0;i<4;i++){
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            
            if(ny>=n || ny<0 || nx>=m || nx<0 ){
                 flag = true;
                 continue;
            }
            
            if(ban_area[ny][nx]){
                flag = true;
                continue;
            }
            if(visit[ny][nx])
                continue;
            if(map[ny][nx]>h){
                high = min(map[ny][nx],high);
                continue;
            }else if(map[ny][nx]==h){
                bq.push({ny,nx});
                visit[ny][nx] = true;
            }
        }
    }
}

void init(){
    fill(visit[0],visit[51],false);
}
//바닥이 b이고 방문한 부분 물 채우기. 높이는 high
//바닥을 
int fill_water(int b,bool flag){

    int ret =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==b && visit[i][j]){            
                if(flag){
                    ban_area[i][j] = true;
                    map[i][j] = 10;
                }else{
                    ret += high-b;
                    map[i][j] = high;
    
                }
                
            }
        }
    }

    return ret;
}

int main() {
    cin>>n>>m;

   

    string s="";
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            map[i][j] = s[j]-'0';
            q[map[i][j]].push({i,j});
        }
    }

    int ans=0;
    for(int i=1;i<10;i++){
        init();
        while(!q[i].empty()){
            if(!visit[q[i].front().first][q[i].front().second]){
                visit[q[i].front().first][q[i].front().second] = true;
                bfs(q[i].front(),i);
                //물 채우기 or 금지 지역 만들기 
                ans += fill_water(i,flag);   
                
            }
            q[i].pop();
        }
    }
    cout<<ans;
    return 0;
}