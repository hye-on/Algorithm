#include <string>
#include <vector>
#include<iostream>

using namespace std;

//10:32
//던전 최대 8개
int answer;
vector<vector<int>> dungeons;
vector<bool>visit;

void dfs(int score, int dun_cnt){
    if(score<0)
        return;
    if(dun_cnt>answer){
        answer = dun_cnt;
        cout<<endl;
    }
    
    for(int i=0;i<dungeons.size();i++){
        if(visit[i])
            continue;
        //최소 필요 피로도가 낮음
        if(score<dungeons[i][0])
            continue;
        visit[i]=true;
        dfs(score-dungeons[i][1],dun_cnt+1);
        visit[i]=false;
    }
}

int solution(int k, vector<vector<int>> _dungeons) {
   
    dungeons = _dungeons;
    visit.resize(dungeons.size());
    dfs(k,0);
    return answer;
}