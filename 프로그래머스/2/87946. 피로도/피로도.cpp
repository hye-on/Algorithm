#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> dungeon;
vector<bool>chk;
int answer;
void dfs(int score,int cnt){
    
    if(score>=0)
        if(cnt>answer)
            answer=cnt;
    if(score<0)
        return;
       
    for(int i=0;i<dungeon.size();i++){
        if(chk[i] || score<dungeon[i][0])
            continue;
        chk[i]=true;
        dfs(score-dungeon[i][1],cnt+1);
        chk[i]=false;
    }
    
}
int solution(int k, vector<vector<int>> dungeons) {

    
    dungeon = dungeons;
    chk.resize(dungeons.size());
    dfs(k,0);
    return answer;
}