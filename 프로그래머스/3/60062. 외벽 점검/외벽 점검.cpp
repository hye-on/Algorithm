#include <string>
#include <vector>
#include <iostream>

using namespace std;

//12:16~1:49
//2:50 ~
//완탐
vector<int> ff(8);
bool visit[8];
vector<int> dd(8);
vector<int> dist;
int cnt;
vector<int> weak;
int answer = -1;
int n;
int a,b;

bool chk(int start){
    //범위 
    int c=0;
    int f = weak[start];
    int b = (f+ff[c++])%n;

    int coverCnt=0;
    int ii=0;
    // if(cnt==3 && weak[start]==30)
    //     cout<<f<<"  "<<b<<"  "<<endl;
    for(int i = start; i<start+weak.size();i++){
        
         ii = i%weak.size();
      
        if(b<weak[ii] && weak[ii]<f){
            //모든 친구 다 썼으면 
            if(c>=cnt)
                break;
            
            f = weak[ii];
            b = (f+ff[c++])%n; 
            // if(cnt==3 && weak[start]==30)
            //     cout<<f<<"  "<<b<<"  "<<endl;
            
        }
        else if(f<b && !(f<=weak[ii] && weak[ii]<=b)){
            if(c>=cnt)
                break;
            
            f = weak[ii];
            b = (f+ff[c++])%n; 
            // if(cnt==3 && weak[start]==30)
            //     cout<<f<<"  "<<b<<"  "<<endl;
        }
        
        if(f>b){
            if(weak[ii]>=b || weak[ii]<=f)
                coverCnt++;
        }else{
            if(f<=weak[ii] && weak[ii]<=b)
                coverCnt++;
        }


    }

  
        
    if(coverCnt==weak.size())
    {   
     //  cout<<weak[start]<<"  "<<ff[0]<<endl;
        answer=cnt;
        return true;
    }
    return false;

}


//투 포인터
void move(){
            //커버할 시작위치
    for(int j=0;j<weak.size();j++){
        if(chk(j))
            return;
    }

}


//순열
void backtracking(int depth,int next){
   if(answer>-1)
       return;
    if(depth==cnt){
        move();
        return;
    }
    
    for(int i=0;i<dist.size();i++){
        if(visit[i])
            continue;
        visit[i] = true;
        ff[depth] = dist[i];
        backtracking(depth+1,i+1);
        visit[i]=false;
    }
}


int solution(int _n, vector<int> _weak, vector<int> _dist) {
    
    weak = _weak;
    dist = _dist;
    n = _n;
    
    for(int i=0;i<dist.size();i++){
        cnt=i+1;
        backtracking(0,0);//최대 	109600
    }
   
    return answer;
}