#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

int num[10000001];
priority_queue<int>pq;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(auto t:tangerine)
        num[t]++;
    
    for(int i=1;i<10000001;i++){
        if(num[i])
            pq.push({num[i]});
    }
    
    for(int i=1;i<10000001;i++){
        k-=pq.top();
        pq.pop();
        if(k<=0){
            answer=i;
            break;
        }
    }
    return answer;
}