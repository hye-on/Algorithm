#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//완전 탐색
// dist에서 1개 고르고  
// dist에서 2개 고르고 

//dist에서 8개 고르고 

//순차적으로 체크 1 5 6 10  1~5, 6~10
int n,m;
vector<int> weak;
vector<int> dist;
//int pick[8];
bool visit[8];


// void backtracking(int depth,int cnt,int idx){
//     if(depth==cnt){
//         return;
//     }
//     for(int i =0;i<dist.size();i++){
//         if(visit[i])
//             continue;
//         visit[i] =true;
//         pick[i] = dist[i];
//         visit[i]=false;
//     }
        
// }
// vector<int> pickF(int cnt,vector<int>& dist){
    
// }
vector<int>pick2;
vector<int>pick;
int answer;

bool findAns;

void rotate(int srt,int k){
    int idx =srt; //weak시작위치
    int size = pick[0];
    int start = weak[srt] ;
    int end = weak[srt] + size;
    int cnt =0;
    int didx=0;
    //m개가 되면 다 커버한것
    
    while(true){
       
        if(idx<weak.size() && start<=weak[idx] && weak[idx]<=end){
            cnt++;
            idx++;
          
        }else{
            
            didx++;
            start = weak[idx];
            end = weak[idx] + pick[didx];
        }
       
        if(didx==k || cnt==m){
            break;
        }
    }
    
    if(cnt==m){
        answer=k;
    }
    
    if(answer>0)
        findAns=true;
        
}

void rotate_op(int srt,int k,vector<int>tmp){
    int idx =srt; //weak시작위치
    int size = pick[0];
    int start = weak[srt] ;
    int end = weak[srt] + size;
    int cnt =0;
    int didx=0;
    //m개가 되면 다 커버한것
    vector<int>weak = tmp;
    reverse(weak.begin(),weak.end());
    while(true){
       
        if(idx<weak.size() && start<=weak[idx] && weak[idx]<=end){
            cnt++;
            idx++;
          
        }else{
            
            didx++;
            start = weak[idx];
            end = weak[idx] + pick[didx];
        }
       
        if(didx==k || cnt==m){
            break;
        }
    }
    
    if(cnt==m){
        answer=k;
    }
    
    if(answer>0)
        findAns=true;
        
}
int solution(int _n, vector<int> _weak, vector<int> _dist) {

    n =_n;
    m = _weak.size();
    weak = _weak;
    dist = _dist;
    
    sort(dist.rbegin(),dist.rend()); //내림차순
    for(int i=0;i<_weak.size();i++){
        weak.push_back(_weak[i]+n);
       
    }
    
    
    sort(weak.begin(),weak.end());
        for(int i=0;i<dist.size();i++){
            //dist에서 i개 고름
            pick = pick2;
            //2개 가능하다면 제일 큰거 2개 고르면 됌
            for(int k=0;k<=i;k++){
                pick.push_back(dist[k]);
            } 
            sort(pick.begin(),pick.end());

        do{
            for(int k=0;k<m;k++){

                rotate(k,i+1);
              //  rotate_op(k,i+1,weak);
                if(findAns)
                    break;
            }
        }while(next_permutation(pick.begin(),pick.end()));
            if(findAns)
                break;

        
            
    }
    
    if(!findAns)
        answer=-1;
    return answer;
}