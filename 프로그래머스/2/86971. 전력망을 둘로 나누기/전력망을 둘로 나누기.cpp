#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

vector<int>map[101];//2~100

int conA,conB;
int cntNode;
void bfs(int node){
    queue<int>q;
    q.push(node);
    bool visit[101] = {false};
    visit[node]=true;
    visit[conB]=true;
    while(!q.empty()){
        int frontNode= q.front();
        q.pop();
       
        for(int i =0 ;i< map[frontNode].size();i++){
            if(visit[map[frontNode][i]])
               continue;
            
            q.push(map[frontNode][i]);
            cntNode++;
            visit[map[frontNode][i]] = true;
        }
        
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    for(int i=0;i<wires.size();i++){
        map[wires[i][0]].push_back(wires[i][1]);
        map[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0;i<wires.size();i++){
        //끊을 연결을 정하고
        cntNode=1;
        conA=wires[i][0];
        conB=wires[i][1];
        
        //완전탐색
        
        bfs(conA);
        answer = min(answer,abs((n-cntNode)-cntNode));
        
        
    }
    
    return answer;
}