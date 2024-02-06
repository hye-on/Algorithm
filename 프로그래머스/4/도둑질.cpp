#include <string>
#include <vector>
#include <algorithm>


using namespace std;
vector<int>dp1; 
vector<int>dp2; 
int solution(vector<int> money) {
    int answer = 0;
    dp1.resize(money.size());
    dp2.resize(money.size());
    int money_size = money.size();
    //첫번째 집을 터는 경우
    dp1[0] = money[0]; 
    dp1[1] = money[0];
    //첫번째 집을 털지 않는 경우
    dp2[0] = 0;       
    dp2[1] = money[1];
    
    for(int i=2;i<money_size;i++){
        if(i!=money_size-1)
            dp1[i] = max(dp1[i-2]+money[i] , dp1[i-1]);
        dp2[i] = max(dp2[i-2]+money[i] , dp2[i-1]);
    }
   
    return answer = max(dp1[money_size-2],dp2[money_size-1]);
}
