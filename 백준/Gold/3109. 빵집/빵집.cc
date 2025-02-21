#include <iostream>
#include <algorithm>

using namespace std;



int r,c;
int map[10000][500];
int visited[10000][500];
int ans= 0;
int cnt=0;
int dy[] = {-1,0,1};
int dx[] = {1,1,1};
bool findAns;
void dfs(pair<int,int>pos){
    int curY = pos.first;
    int curX = pos.second;

    if(curX == c-1){

        findAns = true;
        return ;
    }

    for(int i=0;i<3;i++){
        int ny = curY + dy[i];
        int nx = curX + dx[i];

        if(ny<0 || ny>=r)
            continue;
        if(map[ny][nx]==1 || visited[ny][nx])
            continue;

        visited[ny][nx] = true;
        dfs({ny,nx});
        if(findAns)
            return;
    }

}
int main() {

    cin>>r>>c;

    string input_s="";
    for(int i=0;i<r;i++){
        cin>>input_s;
        for(int j=0;j<c;j++){
            if(input_s[j]=='.')
                map[i][j]=0;
            else
                map[i][j]=1;
        }
    }

    for(int i=0;i<r;i++){
        findAns = false;
        dfs({i,0});
        if(findAns)
            ans++;
    }

   cout<<ans;
    
    return 0;
}