#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_number = truck_weights.size();
    int total_weight =0;
    int truck_cnt=0;
    
    for(int i=0 ; i<truck_number;i++){
        if(total_weight + truck_weights[i] > weight  ){    
            total_weight = truck_weights[i];
            answer+= bridge_length;
        }
        else if ( truck_cnt > bridge_length)
            answer++;
        else{
            if(i==0)
                answer+=bridge_length;
            else
                answer++;
            total_weight += truck_weights[i];
            
        }
      truck_cnt++;
      
    }
    answer++;
    return answer;
}