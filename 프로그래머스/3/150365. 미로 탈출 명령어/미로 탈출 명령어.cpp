#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

//dfs or 그리디
int n,m,r,c,k;
string answer;
// d l r u
int dy[] ={1,0,0,-1};
int dx[] ={0,-1,1,0};
char cc[] ={'d','l','r','u'};

void dfs(string dir,int dist,int i,int j){ 
    if(answer.size()>0)
        return;
    if(dist==0 ){   
        if(i==r && j==c)
            answer=dir;
        return;
    }
    int distance = abs(r-i) + abs(c-j); 
    
   if(distance>dist)
       return;
    
    for(int ii=0;ii<4;ii++){
        int ny = i + dy[ii];
        int nx = j + dx[ii];
        if(ny>=n || ny<0 || nx>=m || nx<0)
            continue;
        distance = abs(r-ny) + abs(c-nx);
        
        if((dist-1-distance)%2==0)
            dfs(dir+cc[ii],dist-1,ny,nx);
    }

}
string solution(int _n, int _m, int x, int y, int _r, int _c, int _k) {
   
    //주어지는 좌표랑 달라서 틀렸음 0인덱스 1인덱스 주의
    n=_n;
    m=_m;
    r=_r-1;
    c=_c-1;
    k=_k;
    x--;
    y--;
    
    int distance = abs(x-r) + abs(y-c);
    if(k<distance)
        return "impossible";
    else if((k-distance)%2==1)
        return "impossible";
    
    dfs("",k,x,y);
       
    return answer;
}