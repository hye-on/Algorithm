#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


//현재 실행할 수 있는 작업중에 제일 업무시간이 작은 작업을 수행한다. 
//1. 업무시간 순으로 정렬 
//2. 현재 시간과 비교
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q2;
int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int time=0;
    //소요시간 순으로 정렬 {작업 소요시간, 작업 요청 시점}
    for(auto j : jobs){
        q.push({j[1],j[0]});
    }
    
    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            if(q.top().second<=time){
                time+=q.top().first;
                answer+=(time-q.top().second);
              //  cout<<answer<<endl;
                q.pop();
        
                break;
            }
            else{
                q2.push(q.top());
                q.pop();
                i--;
            }
           
            if(i==q.size()-1)time++;
        }
        while(!q2.empty()){
            q.push(q2.top());
            q2.pop();
        }
    }

    return answer/jobs.size();
}