#include <string>
#include <vector>
#include<iostream>
#include<cstring>
using namespace std;
//8:54 
vector<int> answer;
int n;
int cntW[11][12];//cntW[a][b] 는 a가 b에게 이긴 횟수
vector<vector<int>> dice;
vector<int> myDice(5);
vector<int> yourDice(5);
int myScore[601]; //최대 점수가 600
int yourScore[601]; //최대 점수가 600
bool visit[10];
int maxW;
void cal(int idx,int sum, bool flag){
    if(idx==n/2){
        if(flag)
            myScore[sum]++;
        else
            yourScore[sum]++;
        return;
    }
    for(int i=0 ; i<6;i++){
        if(flag)
            cal(idx+1,sum+ dice[myDice[idx]][i],flag);
        else
            cal(idx+1,sum+dice[yourDice[idx]][i],flag);
    }
}
int calW(){
    int wC=0;
    for(int i=1;i<601;i++){
        if(myScore[i]==0)
            continue;
        for(int j=1;j<i;j++){
            if(yourScore[j]==0)
                continue;
            wC+=(myScore[i]*yourScore[j]);
        }
            
    }
    return wC;
}
//가능한 조합 고르기
//TODO : 중복되는 계산 있음. 34에서 진것은 12에서 이긴 것이랑 똑같다.
void backtracking(int depth,int idx){
    
    //n/2개 다고름
    if(depth==(n/2)){
        int idx1=0,idx2=0;
        for(int i=0;i<n;i++){
            if(visit[i])
                myDice[idx1++]=i;
            else
                yourDice[idx2++]=i;
        }
       //이긴 경우의수 세기
        cal(0,0,true);
        cal(0,0,false);

        int w = calW();  
        //최대 이긴 경우의 수이면
        if(w>maxW){
            for(int i=0;i<n/2;i++){
                answer[i]=myDice[i]+1;
            }
            maxW=w;
        }
        //myScore,yourScore 초기화
        memset(myScore,0,sizeof(myScore));
        memset(yourScore,0,sizeof(yourScore));
        return;
    }
    for(int i = idx;i<n;i++){
      
        visit[i]=true; 
        backtracking(depth+1,i+1);
        visit[i]=false;
    }
}
vector<int> solution(vector<vector<int>> _dice) {
    
    dice = _dice;
    n = dice.size();
    answer.resize(n/2);
    
    backtracking(0,0);
   
    return answer;
}