#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//기둥 : 바닥, 한쪽만 있는 보, 기등
//보 : 기둥, 양쪽 다른 보 

//11:39
int n;
//보 설치 가능한지
bool isC(int x, int y, vector<vector<pair<int,int>>>&board){//기둥 세울 수 있는지

    //바닥에 설치 불가능
    if(y==0)
        return false;
    //한쪽 끝 부분이 기둥 위에 있어야 함. 양쪽도 가능?
    if(board[y-1][x].first==1 )
        return true;
    if(x+1<=n && board[y-1][x+1].first==1 )
        return true;
    //기둥 위에 없으면 양쪽 끝에 설치 불가능
    if(x==0 || x==n-1)
        return false;
    //양쪽 끝 부분이 다른 보와 동시에 연결
    
    if(x-1<=n)
        if(board[y][x-1].second==1 && board[y][x+1].second==1) 
            return true;
    return false;
}

//기둥 세울 수 있는지
bool isR(int x, int y, vector<vector<pair<int,int>>>&board){

    //바닥이면 설치 가능
    if(y==0)
        return true;
    
     // 다른 기둥 위에 있어야
    if(board[y-1][x].first==1)
        return true;
   
    
    //보 위에 설치 가능 - 양쪽에 보가 있어도 가능?
    if(x-1>=0 && board[y][x-1].second==1)
        return true;
    
    if(board[y][x].second==1){//보 second
        return true;
    }
    
    return false;
}

//보 삭제 할 수 있는지
bool isCD(int x, int y, vector<vector<pair<int,int>>>&board){

    board[y][x].second=0;
    
    for(int i=max(0,y-1);i<=min(n,y+1);i++){
        for(int j=max(0,x-1);j<=min(n,x+1);j++){
           // cout<<"x "<<j<<"  y "<<i<<endl;
            if(board[i][j].first==1){
                //주변 기둥을 다시 설치한다고 가정했을 때 불가능하면 삭제 불가능
                if(!isR(j,i,board)){
                    board[y][x].second=1;
                    return false;
                }
            }
            if(board[i][j].second==1){
                //주변 보들을 다시 설치한다고 가정했을 때 불가능하면 삭제 불가능
                if(!isC(j,i,board)){
                    board[y][x].second=1;
                    return false;
                }
            }
        }
    }
    return true;

}


//기둥 삭제 할 수 있는지
bool isRD(int x, int y, vector<vector<pair<int,int>>>&board){

    board[y][x].first=0;
    
    for(int i=max(0,y-1);i<=min(n,y+1);i++){
        for(int j=max(0,x-1);j<=min(n,x+1);j++){
            if(board[i][j].first==1){
                //주변 기둥을 다시 설치한다고 가정했을 때 불가능하면 삭제 불가능
                if(!isR(j,i,board)){
                    board[y][x].first=1;
                    return false;
                }
            }
            if(board[i][j].second==1){
                //주변 보들을 다시 설치한다고 가정했을 때 불가능하면 삭제 불가능
                if(!isC(j,i,board)){
                    board[y][x].first=1;
                    return false;
                }
            }
        }
    }
    return true;
}



vector<vector<int>> solution(int _n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    n = _n;
    vector<vector<pair<int,int>>>board(n+1,vector<pair<int,int>>(n+1)); //기둥,보
    
    
    
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if(b==0){//삭제
            if(a==0){//기둥 
                if(isRD(x,y,board)){
                    board[y][x].first=0;
                }
                
            }else{//보
               
                if(isCD(x,y,board)){
                    board[y][x].second=0;
                }    
            }
            
            
        }else{//설치
            if(a==0){//기둥 
                if(isR(x,y,board)){
                    board[y][x].first=1;
                }
            }else{//보
                if(isC(x,y,board)){
                    board[y][x].second=1;
                }    
            }
        }
    }
    
    for(int j=0;j<=n;j++){
        for(int i=0;i<=n;i++){
            //기둥이 있으면
            if(board[i][j].first==1){
                vector<int>t(3);
                t[0]=j;t[1]=i;t[2]=0;
                answer.push_back(t);
            }
            //보가 있으면 
            if(board[i][j].second==1){
                vector<int>t(3);
                t[0]=j;t[1]=i;t[2]=1;
                answer.push_back(t);
            }
        }
    }
    
    return answer;
}