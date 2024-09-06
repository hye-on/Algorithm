#include <string>
#include <vector>
#include <iostream>
using namespace std;

//오후 04:13


vector<pair<int,int>>v(1000001); //나간거, 들어온거
vector<int>num[1000001]; //연결 노드
bool check[1000001]; //존재 노드


vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.resize(4);
    
    for(int i=0;i<4;i++)
        answer[i]=0;
    
    for(int i=0;i<edges.size();i++){
        num[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][0]].first++;
        v[edges[i][1]].second++;
        check[edges[i][0]]=true;
        check[edges[i][1]]=true;
    }
    int cnt=0;
    
    for(int i=1;i<1000001;i++){
        if(v[i].first>1 && v[i].second==0){
            answer[0]=i;      
            cnt = v[i].first;       
            for(int j=0;j<num[i].size();j++){
                v[num[i][j]].second--;
                
            }
            break;
        }
    }
    
    for(int i=1;i<1000001;i++){
        if(v[i].first==2 && v[i].second==2)
            answer[3]++;
        if(check[i] && v[i].first == 0 && v[i].second<=1 )
           answer[2]++;
    }
    answer[1]=cnt-(answer[3]+answer[2]);
    return answer;
}