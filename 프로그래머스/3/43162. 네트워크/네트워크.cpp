#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int>node[201];
vector<bool>chk(201,0);

void dfs(int idx){
    chk[idx]=true;
    for(int i=0;i<node[idx].size();i++){
        if(!chk[node[idx][i]])
            dfs(node[idx][i]);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int com_size = computers.size();
    for(int i=0;i<com_size ;i++){
        for(int j=i+1;j<com_size;j++){
            
            if(computers[i][j]){
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }

    
    for(int i=0;i<com_size;i++){
        if(!chk[i]){
            dfs(i);
            answer++;
        }
    }
    return answer;
}