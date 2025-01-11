#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int n, m;


bool visit[5][5]; // 방문 여부(0일 경우 해당 칸이 아직 남아있음을 의미)
vector<vector<int>> block;
//미니맥스 알고리즘 : 상대방의 수를 미리 예측하고 플레이하는 것

// 현재 상태에서 둘 다 최적의 플레이를 할 때 남은 이동 횟수

// 반환 값이 짝수 : 플레이어가 패배함을 의미, 홀수 : 플레이어가 승리함을 의미
    //현재 두고 있는 수부터 마지막 수까지를 카운트, 즉 A,B 둘다 홀수가 내가 이긴것

// curx, cury : 현재 플레이어의 좌표, opx, opy : 상대 플레이어의 좌표
int solve(int curx, int cury, int opx, int opy){
    // 플레이어가 밟고 있는 발판이 사라졌다면
    if(visit[curx][cury]) return 0;    
    int ret = 0;
    // 플레이어를 네 방향으로 이동시켜 다음 단계로 진행할 예정
    for(int dir = 0; dir < 4; dir++){
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        //범위 밖
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;
        //방문해서 발판 없는 경우 or 발판이 없을 경우
        if(visit[nx][ny] || !block[nx][ny]) 
            continue;
        
        //상대방이 어떻게 하느냐에 따라 달라짐 
        visit[curx][cury] = 1; //방문      
        int val = solve(opx, opy, nx, ny)+1;      
        visit[curx][cury] = 0;        
        
        //항상 최적의 경로로 가야함
        // 지고 있는데 이길 수 있는 경우
        if(ret % 2 == 0 && val % 2 == 1) ret = val; 
        // 모두 질 경우 , 더 늦게 지는것을 택함
        else if(ret % 2 == 0 && val % 2 == 0) ret = max(ret, val); 
        // 이길 수 있는 경우 더 빨리 이길 수 있는 것 택함
        else if(ret % 2 == 1 && val % 2 == 1) ret = min(ret, val);
        
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    
    n = board.size();
    m = board[0].size();
    block = board;
    return solve(aloc[0], aloc[1], bloc[0], bloc[1]);
}