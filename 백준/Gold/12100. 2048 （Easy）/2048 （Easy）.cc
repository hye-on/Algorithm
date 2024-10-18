#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1:17
//상하좌우 순열로 뽑고
//움직이면서 최댓값 갱신
int n;


int move(vector<vector<int>> &map,int dir){
    //합쳐졌는지 여부
    vector<vector<bool>> chk(n,vector<bool>(n,false));
    
     if(dir==0){ //아래

          for(int j=0;j<n;j++){ //x축
            for(int i=n-1;i>=0;i--){
                //움직일 필요 없거나 벽쪽이면 스킵
                if(map[i][j]==0 || (i+1)>=n)
                    continue;
                int toY = i+1;
               
                while(toY<n){
                    if(map[toY][j]==0){ //빈칸이면
                        map[toY][j] = map[toY-1][j];
                         map[toY-1][j] = 0;
                    }
                    else{
                        if(!chk[toY][j]&& !chk[toY-1][j] && map[toY][j]==map[toY-1][j]){ //같은 숫자이면 합치기
                            map[toY][j]*=2;
                            map[toY-1][j] =0;
                            chk[toY][j]=true;
                        }
                        //다른 숫자거나 같은 숫자인데 이미 합친 적이 있으면 아무것도 하지 않음
                    }
                    toY++;
                }
            }
        }

        // cout<<"0  ====================="<<endl;
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //        cout<<map[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        // cout<<endl;
        
    }else if(dir==1){ //오른쪽

         for(int i=0;i<n;i++){ //y축
            for(int j=n-1;j>=0;j--){
                //움직일 필요 없거나 벽쪽이면 스킵
                if(map[i][j]==0 || (j+1)>=n)
                    continue;
                int toX = j+1;
               
                while(toX<n){
                    if(map[i][toX]==0){ //빈칸이면
                        map[i][toX] = map[i][toX-1];
                         map[i][toX-1] = 0;
                    }
                    else{
                        if(!chk[i][toX]&& !chk[i][toX-1] && map[i][toX]==map[i][toX-1]){ //같은 숫자이면 합치기
                            map[i][toX]*=2;
                            map[i][toX-1] =0;
                            chk[i][toX]=true;
                        }
                        //다른 숫자거나 같은 숫자인데 이미 합친 적이 있으면 아무것도 하지 않음
                    }
                    toX++;
                }
                
            }
        }
        // cout<<"1=============================="<<endl;

        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //        cout<<map[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        // cout<<endl;
        
    }else if(dir==2){ //위
        for(int j=0;j<n;j++){ //x축
            for(int i=0;i<n;i++){
                //움직일 필요 없거나 벽쪽이면 스킵
                if(map[i][j]==0 || (i-1)<0)
                    continue;
                int toY = i-1;
               
                while(toY>=0){
                    if(map[toY][j]==0){ //빈칸이면
                        map[toY][j] = map[toY+1][j];
                         map[toY+1][j] = 0;
                    }
                    else{
                        if(!chk[toY][j] && !chk[toY+1][j] && map[toY][j]==map[toY+1][j]){ //같은 숫자이면 합치기
                            map[toY][j]*=2;
                            map[toY+1][j] =0;
                            chk[toY][j]=true;
                        }
                        //다른 숫자거나 같은 숫자인데 이미 합친 적이 있으면 아무것도 하지 않음
                    }
                    toY--;
                }
            }
        }

        // cout<<"2======================="<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //        cout<<map[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        // cout<<endl;
        
    }else{//왼쪽

          for(int i=0;i<n;i++){ //y축
            for(int j=0;j<n;j++){
                //움직일 필요 없거나 벽쪽이면 스킵
                if(map[i][j]==0 || (j-1) < 0)
                    continue;
                int toX = j-1;
               
                while(toX>=0){
                    if(map[i][toX]==0){ //빈칸이면
                        map[i][toX] = map[i][toX+1];
                         map[i][toX+1] = 0;
                    }
                    else{
                       
                        if(!chk[i][toX]&& !chk[i][toX+1] && map[i][toX]==map[i][toX+1]){ //같은 숫자이면 합치기
                            map[i][toX]*=2;
                            map[i][toX+1] =0;
                            chk[i][toX]=true;
                        }
                        //다른 숫자거나 같은 숫자인데 이미 합친 적이 있으면 아무것도 하지 않음
                    }
                    toX--;
                }
                
            }
        }
        // cout<<"3=============================="<<endl;

        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //        cout<<map[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        // cout<<endl;
        
    }
    int maxN=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxN = max(maxN, map[i][j]);
        }
    }

    return maxN;
}
int res=0;

void BruteForce(vector<vector<int>> map, int depth){


    
    if(depth==5)
        return ;
    //map에서 모든 것을 dir 방향으로 움직이기


    
    for(int i=0; i<4 ;i++){
        vector<vector<int>> mapT = map;
       // cout<<"depth "<<depth<<endl;
        res = max(res, move(mapT,i));
        BruteForce(mapT,depth+1);
    }
   
 
}

int main() {

    cin>>n;
    
    vector<vector<int>>board(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    BruteForce(board,0);

    cout<<res<<endl;
    return 0;
}