#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int prev = 1;
    int size = stations.size();
    int distance=0;
    int range = 2*w+1;
    for(int i=0;i<size;i++){
        distance = stations[i]-prev-w;
        // cout<<stations[i]<<" "<<prev<<endl;
        // cout<<distance<<endl;
        prev = stations[i]+w+1; 
        if(distance<=0)
            continue;
        answer+=(distance/range);
        if(distance%range!=0)
            answer++;
        
    }
    
    distance = n-stations[size-1]-w;
    if(distance>0){
        answer+=(distance/range);
        if(distance%range)
            answer++;
    }

    return answer;
}