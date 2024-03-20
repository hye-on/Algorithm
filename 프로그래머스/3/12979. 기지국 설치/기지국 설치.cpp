#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    bool chk =false;
    if(stations[stations.size()-1]!=n){
        stations.push_back(n); 
        chk=true;
    }
    int size = stations.size();
    int range = 2*w+1;
    if(stations[0]-1-w>0){
        if((stations[0]-1-w)%range)
            answer += (stations[0]-1-w)/range+1;
        else
            answer += (stations[0]-1-w)/range;
    }
    int distance=0;
    for(int i=1;i<size;i++){
        
        if(i==size-1){
            distance = stations[i]-stations[i-1]-w;
            if(!chk)
                distance-=(w+1);
        }
        else
            distance = stations[i]-stations[i-1]-range;
        
        
        if(distance<0)
            continue;
        if(distance%range){
            answer+=distance/range+1;
           // cout<<distance/range+1<<endl;
        }
        else{
            answer+=distance/range;
           // cout<<distance/range<<endl;
        }
        
    }

    return answer;
}