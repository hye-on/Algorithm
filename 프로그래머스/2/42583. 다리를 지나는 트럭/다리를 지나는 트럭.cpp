#include <string>
#include <vector>
#include <iostream>
#include  <queue> 
using namespace std;

queue<int>bridge;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_number = truck_weights.size();
    int total_weight =0;
    int truck_cnt=0;
    int index=0;
    for(int i = 0 ;i<1000000;i++){
        
        if(bridge.size() == bridge_length){
            if(bridge.front()!=0)
            {    
                total_weight-=bridge.front();
                truck_cnt--;
            }
            bridge.pop();
                    
        }
        
        if(total_weight + truck_weights[index] > weight || truck_cnt + 1 > bridge_length ){
            bridge.push(0);
            //cout<<total_weight<<endl;
            continue;
        }
        
        bridge.push(truck_weights[index]);
        truck_cnt++;
        total_weight+=truck_weights[index++];
        if(index  == truck_number){
            answer= i + bridge_length +1;
            
            break;
        }
    }


    return answer;
}