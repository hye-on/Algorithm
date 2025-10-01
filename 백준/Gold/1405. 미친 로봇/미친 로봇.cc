#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 5:40 완전탐색
// depth가 n
// 방문기록 체크, 확률 계산해서 같이 넘기기

int n;
double dir_num[4];
bool visit[40][40]; // n이 최대 14니까 상하좌우 최대 14
double answer;
int dx[] = {1, -1, 0, 0};  
int dy[] = {0, 0, -1, 1};  

void brute_force(int depth, double value, pair<int,int>pos){

    if(depth==n){
        answer += value;
        return;
    }

    int x =  pos.first;
    int y =  pos.second;
    
    

    for(int i=0;i<4;i++){
        if(dir_num[i] == 0) continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(visit[nx][ny])
            continue;
        
        visit[nx][ny] = true;
        brute_force(depth + 1,value * dir_num[i]*0.01,{nx,ny});
        visit[nx][ny] = false;
        
    }
    
}

int main() {

    cin>>n>>dir_num[0] >> dir_num[1] >> dir_num[2] >> dir_num[3];

    visit[15][15] = true;
    brute_force(0,1, {15,15});

    cout << fixed << setprecision(10) << answer << endl;
    return 0;
}