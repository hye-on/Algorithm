#include <string>
#include <vector>
#include<iostream>
using namespace std;
char map[5][5];
int y,x;
vector<int> answer;


int distance(int yy , int xx){
    //가로 세로 +1씩 체크
    if(xx+1<5 && map[yy][xx+1]=='P')
        return 0;
    if(xx-1>=0 && map[yy][xx-1]=='P')
        return 0;
    if(yy+1<5 && map[yy+1][xx]=='P')
        return 0;
    //가로 세로 +2 씩 체크
    if(xx+2<5 && map[yy][xx+2]=='P' && map[yy][xx+1]=='O')
        return 0;
    if(xx-2>=0 && map[yy][xx-2]=='P' && map[yy][xx-1]=='O')
        return 0;
    if(yy+2<5 && map[yy+2][xx]=='P' && map[yy+1][xx]=='O')
        return 0;
    
    //대각선 체크
    if(yy+1<5 && xx+1<5 && map[yy+1][xx+1]=='P'){
        if(map[yy+1][xx]=='O' || map[yy][xx+1]=='O'){
            return 0;
        }
    }
    if(yy+1<5 && xx-1>=0 && map[yy+1][xx-1]=='P'){
        if(map[yy+1][xx]=='O' || map[yy][xx-1]=='O')
            return 0;
    }
    
    return 1;
}
void solve(){
   for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
               if(map[i][j]=='P'){
                   if(distance(i,j)==0){
                      // cout<<i<<"  "<<j<<endl;
                       answer.push_back(0);
                       return;
                   }
                   
               }  
            }
   }
     answer.push_back(1);
    
}
vector<int> solution(vector<vector<string>> places) {
    
    
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                map[i][j]=places[k][i][j];
                
            }
        }
        solve();
       
    }
   
    return answer;
}