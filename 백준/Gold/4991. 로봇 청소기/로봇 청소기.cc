#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

//11:38
//10! -> 3628800
//dfs? 필요없는 공간을 들릴 일이 많을 것 같다.
//더러운 칸은 10개 이하:  10! 시간 충분할듯
//순서대로 가다가 다른 더러운칸을 청소하게 되면?  ex) 1342 순으로 가려고 했는데 1->3일때 2를 청소하게 될수도 있음. 그래도 1234에서 최소값이 갱신됨
//경로 사이는 bfs 1~10 마다 다 bfs로 최소 경로를 저장해두기

int c,r;//가로, 세로
string tmp;
char graph[20][20];
map<pair<pair<int,int>,pair<int,int>>,int>dist; // 1,2 랑 3,4 의 최소 거리 3, 반대도 저장해야함
pair<int,int>start;
set<pair<int,int>>dirty_pos;

void bfs(pair<int,int>st){
    queue<pair<int,pair<int,int>>>q; //거리 {y,x};
    q.push({0,st});
    
    int dy[] ={0,1,0,-1};
    int dx[] ={1,0,-1,0};
    bool visit[20][20];
    memset(visit,false,sizeof(visit));
    visit[st.first][st.second]=true;
   
    while(!q.empty()){
        int d = q.front().first;
        pair<int,int>curNode =  q.front().second;
        int curY = curNode.first;
        int curX = curNode.second;
        q.pop();
       
        if(st!=curNode && dirty_pos.find({curNode})!=dirty_pos.end()){
            dist[{st,curNode}] =d;
            dist[{curNode,st}] = d;
        }

        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny>=r || ny<0 || nx>=c || nx<0)
                continue;
            if(visit[ny][nx])
                continue;
           
            if(graph[ny][nx]=='x')
                continue;
            
          
            visit[ny][nx]=true;
            q.push({d+1,{ny,nx}});
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    
    cout.tie(NULL);

    do{
        cin>>c>>r;
        if(c==0 && r==0)
            break;
        vector<pair<int,int>>dirty;
        dirty_pos.clear();
        dist.clear();
        for(int i=0;i<r;i++){
            
            cin>>tmp;
            for(int j=0;j<c;j++){
                
                graph[i][j]=tmp[j];
                
                if(graph[i][j]=='*'){
                    dirty.push_back({i,j});   
                    dirty_pos.insert({i,j});
                }
                if(graph[i][j]=='o'){
                    start.first=i;
                    start.second=j;
                   
                }
                    
            }
        }
            //시작점에서도 bfs, dirty bfs   
            
            bfs(start);
            
            for(int i=0;i<dirty.size();i++)
                bfs(dirty[i]);

            
            //순열로 최소 값 구하기
            sort(dirty.begin(),dirty.end());
            int answer=210000000;

        
            do{
                int sum=dist[{start,dirty[0]}];
                if(sum == 0) continue; 
                bool valid = true;
                for(int i=0;i<dirty.size()-1;i++){
                    if(dist[{dirty[i],dirty[i+1]}]==0){
                        valid = false;
                        break;
                    }
                    sum+=dist[{dirty[i],dirty[i+1]}];
                    if (sum >= answer) { // 가지치기
                        valid = false;
                        break;
                    }
                    
                }
                if (valid) answer = min(answer, sum);
               
            }while(next_permutation(dirty.begin(),dirty.end()));

        if(answer==210000000)
            cout<<-1<<'\n';
        else
            cout<<answer<<'\n';
                
        

    }while(true);

    
    return 0;
}