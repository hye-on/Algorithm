#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
//그리디
//먼저 떨어트리고 그 다음 조합

//필요한 변수
//리프노드에 들어간 숫자 개수
// 도착한 리프노드 순서 -> 사전순을 위해
 queue<int>link[102];
int n;
vector<int>node;   
vector<int> target;
vector<int>v;
int drop(vector<int>&node){
    int cur =1;
    int next=0;
    while(true){
        
        //리프노드
        if(link[cur].empty()){
            v.push_back(cur-1);
          
            node[cur-1]++;
            
            int ret =1;
            for(int i=0;i<n;i++){
                 //블가능 하면 0 
                if(target[i]==0 && node[i]>0){
                    ret =0;
                    break;
                }
                //1로 채워도 타겟보다 클 때 
                if(target[i]>0 && node[i]> target[i]){
                    ret =0;
                    break;
                }
                 //더 떨어트려봐야 알 것 같으면 2
                if(target[i]>0 && node[i]*3<target[i])   
                    ret=2;
                
            }
           
           
            return ret;
        }
        next = link[cur].front();
        link[cur].push(link[cur].front());
        link[cur].pop();
        cur = next;
      
    }
    
}
vector<int> solution(vector<vector<int>> edges, vector<int> _target) {
    vector<int> answer;
    target = _target;
    priority_queue<int>linkT[102];
    node.resize(target.size());
    n = target.size();
    for(int i=0;i<edges.size();i++){
        int p = edges[i][0];
        int c = edges[i][1];
        linkT[p].push(-c);
      
    }
    
    //벡터에 자식노드 다 담고 큐에 담기
    for(int i=1;i<=n;i++){
        while(!linkT[i].empty()){
            link[i].push(-linkT[i].top());
            linkT[i].pop();
        }
    }
    
    //target을 만들 수 있는 최소 개수만큼 공을 떨어트리기
    while(true){
        int ret = drop(node);
       
        if(ret==0){
            answer.push_back(-1);
            return answer;
        }
        
        if(ret==1)
            break;
           
        
    }
    //사전순으로 가장 빠른 경우 만들기 
    for(int i=0;i<v.size();i++){
       // cout<<v[i]<<" ";
        int curNode = v[i];
        int score = target[curNode];
        int nodeCnt = --node[curNode]; //남은 노드 개수
        
       
       
        //1을 넣을 수 있으면 넣기 : 남은 노드를 3으로 채웠을때 점수를 충족시킬 수 있다면
        if(nodeCnt*3>=score-1){
            answer.push_back(1);  
            target[curNode]-=1;
        }
        //2를 넣을 수 있으면 넣기
        else if(nodeCnt*3>=score-2){
            answer.push_back(2);
            target[curNode]-=2;
        }else{
        //3을 넣기 
            answer.push_back(3);
            target[curNode]-=3;
        }
    }
    
   
    return answer;
}