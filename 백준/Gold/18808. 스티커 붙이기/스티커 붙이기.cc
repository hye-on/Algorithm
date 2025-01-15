#include <iostream>
#include<vector>
using namespace std;
//12 ~1, 2~2:20

//구현
//40, 40, 100
// 100(스티커 개수)*10*10(스티커)*40*40(격자)*4(회전)
int n,m,k;
int r,c;
int answer;
vector<vector<int>>grid(50,vector<int>(50));
vector<vector<int>>grid_t(50,vector<int>(50));


void rotate(vector<vector<int>>&sti){
   
    vector<vector<int>>sticker_t(sti[0].size(),vector<int>(sti.size(),0));
    for(int i=0;i<sti.size();i++){
        for(int j=0;j<sti[0].size();j++){
            sticker_t[j][sti.size()-i-1] = sti[i][j];
        }
    }
    sti = sticker_t;

    
}

bool put(int y,int x,vector<vector<int>>&sti){
    
    grid_t = grid;

    for(int i=y;i<y+sti.size();i++){
        for(int j=x;j<x+sti[0].size();j++){
            //스티커가 영역 밖에 나가면
            if(sti[i-y][j-x]==1 && (i>=n ||j>=m ))
                return false;
            grid_t[i][j] +=sti[i-y][j-x];
            if(grid_t[i][j]>=2){
                return false;
            }
        }
    }
    grid = grid_t;
    return true;
}

void match( vector<vector<int>>&sti){
     vector<vector<int>>sticker_t;
    sticker_t = sti;
                
     for(int t=0;t<4;t++){
      

         for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){ 
                      
                        if(put(i,j,sticker_t)){   
                            return;
                        }
                       
                       
                   }
               }
         rotate(sticker_t);
        
        }
      
  
}


int main() {

    cin>>n>>m>>k;
    answer = n*m;
   

   while(k--){
        cin>>r>>c;
         vector<vector<int>>sticker(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>sticker[i][j];
            }
        }

      
        match(sticker);
     
   } 
    //빈칸 빼기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!grid[i][j])
                answer--;
        }
    }
    cout<<answer;
    return 0;
}