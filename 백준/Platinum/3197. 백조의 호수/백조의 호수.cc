#include <iostream>
#include <vector>
#include<queue>

using namespace std;
//2:01

int r,c;
char lake[1501][1501];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
vector<vector<bool>>visit(1500,vector<bool>(1500,false));
queue<pair<int,int>>sq;
queue<pair<int,int>>tmpSq;

queue<pair<int,int>>wq;
queue<pair<int,int>>tmpWq;

pair<int,int>start;


bool bfs(){
   
   
    while(!sq.empty()){
        int curY = sq.front().first;
        int curX = sq.front().second;
        
        if(start != sq.front() && lake[curY][curX]=='L'){
           
            return true;
        }
        
        sq.pop();
        
        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny>=r || ny<0 || nx>=c || nx<0 ||  visit[ny][nx])
                continue;
             visit[ny][nx]=true;
            
            //다음에 녹을 자리
            if(lake[ny][nx]=='X'){
                tmpSq.push({ny,nx});
                continue;
            }
            sq.push({ny,nx});
           
        }
    }
    return false;
}
void melt(){

    while(!wq.empty()){
         int curY = wq.front().first;
        int curX = wq.front().second;
            
        wq.pop();
        
        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny>=r || ny<0 || nx>=c || nx<0 )
                continue;
             
            if(lake[ny][nx]=='X'){
                lake[ny][nx] ='.';
                tmpWq.push({ny,nx});
                continue;
            }
           
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>r>>c;

    //X 빙판, L 백조

    string t="";
    for(int i=0;i<r;i++){
         cin>>t;
        for(int j=0;j<c;j++){ 
            lake[i][j] =t[j];
            if(lake[i][j]=='L'){
                start.first = i;
                start.second = j;
            }
            if(lake[i][j]!='X'){
                wq.push({i,j});
            }
            
        }
    }
    visit[start.first][start.second] =true;
    sq.push(start);
    int answer=0;
    while(true){
    //만날 수 있는지 체크
        if(bfs()){
            break;            
        }
   
     //호수 녹이기
        melt();
        answer++;
        sq = tmpSq;
        wq = tmpWq;
        while (!tmpSq.empty()) tmpSq.pop();
        while (!tmpWq.empty()) tmpWq.pop();
        
    }
    cout<<answer;
    return 0;
}