#include <string>
#include <vector>

using namespace std;
//0605~0621 정확도만 맞음확도만 맞음
//시간초과 날 것 같은데 그리디 말고 방법이 생각 안남
//누적합
int type;
int r1,c1,r2,c2,degree;
int sum[1001][1001];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int answer = 0;
    
    for(int i=0;i<skill.size();i++){
        
        type = skill[i][0];
        r1 = skill[i][1];
        c1 = skill[i][2];
        r2 = skill[i][3];
        c2 = skill[i][4];
        degree = skill[i][5];
        degree = type == 1 ? degree * -1 : degree;
            
        sum[r1][c1] += degree;
        sum[r2 + 1][c2 + 1] += degree;
        sum[r1][c2 + 1] -= degree;
        sum[r2 + 1][c1] -= degree;
        

        
    }
    
    for (int i = 0; i <= board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            sum[i][j + 1] += sum[i][j];
        }
    }
 
    for (int j = 0; j <= board[0].size(); j++) {
        for (int i = 0; i < board.size(); i++) {
            sum[i + 1][j] += sum[i][j];
        }
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){    
            if(board[i][j]+sum[i][j]>0)
                answer++;
        }
    }
    return answer;
}