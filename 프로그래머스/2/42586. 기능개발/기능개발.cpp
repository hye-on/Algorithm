#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

queue<int> leftDay;
int cnt=1;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int proSize = progresses.size();
    //1. 스택에 남은 작업 일수를 담는다.
    for(int i = 0 ; i< proSize; i++){
        int day = (100-progresses[i])%speeds[i] ? (100-progresses[i])/speeds[i]+1 : (100-progresses[i])/speeds[i];
        leftDay.push(day);
    }
   
    
    //2. 하나씩 꺼내면서 배포할 수 있는 기능의 개수를 정한다. 
    // 뒤에 나오는 작업 일수가 스택의 맨 앞에 나오는 작업일수보다 작다면 같이 배포할 수 있다.
    // 배포후 스택에서 남은 작업 일수를 삭제한다.
    
    for(int i = 0 ; i< proSize; i++){
        
        int frontDay = leftDay.front();
        leftDay.pop();
        cnt=1;
        
        while(true){
            if(leftDay.size()==0){
                answer.push_back(cnt);
                return answer;
            }
            
            int nextDay= leftDay.front();
            if(nextDay<=frontDay){    
                cnt++;
                leftDay.pop();   
            }
            else{
                answer.push_back(cnt);
                break;
            } 
                
        }
    }
    return answer;
}