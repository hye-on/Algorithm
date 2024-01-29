#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int,int>>bridge; //섬,비용
int parent[101];
int getParent(int node){
    if(parent[node]==node) return node;
    return parent[node] = getParent(parent[node]);
}

bool cmp(vector<int> a, vector<int>b){
    return a[2] <b[2];
}

int solution(int n, vector<vector<int>> costs) {
  int answer=0;
    for(int i=0;i<n;i++)
        parent[i]=i;
    
    sort(costs.begin(), costs.end(), cmp);

    
    for(int i=0;i<costs.size();i++){
        int from = getParent(costs[i][0]);
        int to = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(from!=to){
            answer+=cost;
            parent[to] =from;
        }
        
    }
    
    return answer;
}