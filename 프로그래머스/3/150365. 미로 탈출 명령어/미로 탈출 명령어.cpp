#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
//7:12
char map[51][51];
string ans;


//구조체 비교함수 기억안나서 (자신없어서) pair사용
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char dir[] = {'d','l','r','u'};
int k,n,m,r,c;

int GetDist(pair<int, int> cur)
{
    return abs(r- cur.first) + abs(c - cur.second);
}

void dfs(int cnt,pair<int,int> node, string d){

        if(ans.size()>0)
            return;

        int cur_x = node.first;
        int cur_y = node.second;
    
        if((k-cnt-GetDist(node)) < 0  || (k-cnt-GetDist(node))%2 == 1)
        return;
    
        if(cnt>k)
            return;

        if(cnt==k){
            if(cur_x == r && cur_y == c){
                ans = d;
                return;     
            }
            return;
        }
        
        for(int i=0;i<4;i++){

            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(ny>m || ny<=0 || nx>n || nx<=0)
                continue;
            d+=dir[i];
            dfs(cnt+1,{nx,ny},d);
            d.pop_back();
            
        }
 
    
}
string solution(int _n, int _m, int x, int y, int _r, int _c, int _k) {
    string answer = "impossible";
    k= _k;
    n= _n;
    m= _m;
    r= _r;
    c= _c;
    int distance = abs(x-r) +abs(y-c);
  //  cout<<distance-k;
    if((k-distance)%2 !=0 || k < distance )
        return answer;
        
    dfs(0,{x,y},"");
   if(ans.size()>0)
       answer = ans;

    
    
    return answer;
}