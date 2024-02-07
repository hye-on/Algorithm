#include<vector>
#include<queue>

using namespace std;
int answer =-1;
int n,m;
int dir_y[] = {1,0,-1,0};
int dir_x[] = {0,1,0,-1};
vector<vector<int>> graph;
vector<vector<bool>> visit(101,vector<bool>(101,false));
vector<vector<int>> cnt(101,vector<int>(101,0));

void bfs(int y, int x){
    
    queue<pair<int,int>>node;
    node.push({y,x});
    cnt[0][0]=1;
    while(!node.empty()){

        int y = node.front().first;
        int x = node.front().second;
        node.pop();
        if(y==m && x==n){
            answer=cnt[y][x];
           break; 
        }
        for(int i=0;i<4;i++){
            int dy= y + dir_y[i];
            int dx= x + dir_x[i];
            if(dy<0 || dy>m || dx<0 || dx>n)
                continue;
            if(visit[dy][dx])
                continue;
            if(graph[dy][dx]){
                visit[dy][dx]=true;
                node.push({dy,dx});
                graph[y][x]=0;
                cnt[dy][dx]=cnt[y][x]+1;
            }


        }
    }
      
}
int solution(vector<vector<int> > maps)
{
    m = maps.size()-1;    //세로
    n = maps[0].size()-1; //가로
    graph= maps;
    bfs(0,0);
    return answer;
}