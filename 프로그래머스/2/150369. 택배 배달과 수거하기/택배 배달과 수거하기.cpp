#include <string>
#include <vector>
#include <queue>
using namespace std;


// 멀리 있는 애부터 배달 - 돌아오면서 수거
// 1:52


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    
    int deliverySum = 0;
    int pickupSum = 0;
    
    for(int i = n-1; i >= 0; i--){
        int cnt = 0;
        deliverySum += deliveries[i];
        pickupSum += pickups[i];
        
        // 배달과 수거 둘다 0이하가 될때까지 트럭이 그 지점까지 가야하기 때문에. 
        // 만약 배달이나 수거가 -가 되면 {거리가 짧은것}을 미리 처리한 것으로!
        while(deliverySum > 0 || pickupSum > 0)
        {
            deliverySum -= cap;
            pickupSum -= cap;
            cnt++;
        }
        answer += (i+1) * 2 * cnt;
    }
    
    return answer;
}