#include <string>
#include <vector>
#include<iostream>
using namespace std;


vector<string> board;
bool visit[31][31];
int from=0,to=0;
bool excute;
int n,m;

void remove(){
    
     for(int x=0;x<n;x++){
         from =m-2;to=m-1;
         for(int y=to;y>=0;y--){
             if(visit[y][x] || board[y][x]=='.'){
                 to=y;
                 //to 찾기
                 from=to;
                 while(from>=0){
                     //cout<<"From "<<from<<endl;
                     if(!visit[from][x] && board[from][x]!='.'){
                         //내리기
                         board[to][x]=board[from][x];
                         board[from][x]='.';
                         break;
                     }
                     from--;
                 }
                 
                 if(from==-1)
                     board[to][x]='.';
                 
             }
                 
         }
     }
}

void find(int y,int x){
    if(board[y][x]=='.')
        return;
    if(board[y][x]==board[y][x+1] && board[y][x]==board[y+1][x] && board[y][x]==board[y+1][x+1]){
        visit[y][x]=true;
        visit[y][x+1]=true;
        visit[y+1][x]=true;
        visit[y+1][x+1]=true;
        excute=true;
    }
}

int solution(int _m, int _n, vector<string> _board) {
    int answer = 0;
    n=_n;
    m=_m;
    board=_board;
    
    while(true){
        
  //초기화
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j])
            {    answer++;
                 visit[i][j]=false;
            }
        }
    }
        
    //4*4블록 지우기
    excute=false;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            find(i,j);
        }
    }
    if(!excute)
        break;
    
    remove();
    
    }
    
    
    return answer;
}