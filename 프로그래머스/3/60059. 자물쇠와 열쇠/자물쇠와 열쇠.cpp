#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> lock(60,vector<int>(60,0));
vector<vector<int>> key;
int l_size;
int k_size;
//07:30~8:23
bool sol(int y,int x, vector<vector<int>> lock){
    int sum=0;
    for(int i=0;i<k_size;i++){
        for(int j=0;j<k_size;j++){
            sum = key[i][j] + lock[y+i][x+j];
            //out of bounds
            if(y+i<k_size-1 || x+j<k_size-1 || y+i>=k_size+l_size-1|| x+j>=k_size+l_size-1)
                continue;
            if(sum==2 || sum==0)
                return false;
            lock[y+i][x+j]=1;
        }
    }
    
    //다 1이 되었는지 검사
    for(int i=0;i<l_size;i++){
        for(int j=0;j<l_size;j++){
            if(lock[i+k_size-1][j+k_size-1]==0)
                return false;
        }
    }
    
    return true;
}

void rotate(){
    vector<vector<int>> new_key(k_size,vector<int>(k_size,0));
    for(int i=0;i<k_size;i++){
        for(int j=0;j<k_size;j++){
            new_key[j][k_size-1-i] = key[i][j];
        }
    }
    
    key= new_key;
}


bool solution(vector<vector<int>> _key, vector<vector<int>> _lock) {
    bool answer = true;
    key = _key;
    l_size= _lock.size();
    k_size = key.size();

    
    for(int i=0;i<l_size;i++){
        for(int j=0;j<l_size;j++){
            lock[i+k_size-1][j+k_size-1] = _lock[i][j];
        }
    }
    

    bool isPos = false;
    int k=0;

    
    do{
        for(int i=0; i<l_size + k_size -1 ;i++){
            for(int j=0; j<l_size + k_size -1 ;j++){
                isPos = sol(i,j,lock);
                
                if(isPos)
                    break;
            }
            if(isPos)
                    break;
        }
        if(isPos)
            break;
        //key 회전
        rotate();
        // cout<<endl;
        // for(int i=0;i<k_size;i++){
        //     for(int j=0;j<k_size;j++){
        //         cout<<key[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
       
    }while(k++<3);
    
    return isPos;
}