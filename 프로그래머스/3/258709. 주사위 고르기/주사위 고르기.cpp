#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

//4:16
//2차원 배열에 주사위 1:1로 비교했을 때 이길 수 있는 경우의 수 저장
//조합으로 2:2로 팀 나눠서 계산
int n;
vector<int>num;
vector<vector<int>> dice;
set<string>chk;

void cntCase(int idx,int depth,int sum,map<int,int>&m){
    if(idx == depth){
        m[sum]++;
        return;
    }
    for(int i=0;i<6;i++){
        cntCase(idx+1,depth,sum+dice[num[idx]][i],m);
    }
}

int calWin(){
    //6개의 면
    int aWin=0;
    int bWin =0;
    map<int,int>myScore;
    map<int,int>yourScore;
    cntCase(0,n/2,0,myScore);
    cntCase(n/2,n,0,yourScore);
    
    for(auto it = myScore.begin();it!=myScore.end();it++){
        for(auto it2 = yourScore.begin();it2!=yourScore.end();it2++){
            int t1 = it->first;
            int t2 = it2->first;
            if(t1>t2)
                aWin+=(it->second*it2->second);
            else if(t1<t2)
                bWin+=(it->second*it2->second);
        }
    }

    return aWin;
    
}
vector<int> solution(vector<vector<int>> _dice) {
    dice  = _dice;
    vector<int> answer;
     n = dice.size();
    answer.resize(n/2);
    
    vector<vector<int>>winCnt(n,vector<int>(n,0));
     
    for(int i=0;i<n;i++)
        num.push_back(i);
    
    
    // 조합으로 2:2로 팀 나눠서 계산
    int ans=0;
    int du =0;
    int maxWin=0;
    string temp="";
    do{
       temp="";
        for(int i=0;i<n/2;i++)
            temp+=num[i]+'0';
        sort(temp.begin(), temp.end());
        if(chk.find(temp)!=chk.end())
            continue;
        chk.insert(temp);
       
        int t = calWin();
     
        if(t>maxWin){
           
            for(int i=0;i<n/2;i++)
                answer[i] = num[i]+1;
            maxWin=t;
        }
       
    }while(next_permutation(num.begin(),num.end()));
    sort(answer.begin(),answer.end());
    return answer;
}