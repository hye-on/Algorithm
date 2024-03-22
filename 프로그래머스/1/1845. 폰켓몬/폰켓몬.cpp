#include <vector>
#include<set>
using namespace std;

set<int>s;
int solution(vector<int> nums)
{
    int answer = 0;
    for(auto n : nums){
        s.insert(n);
    }
    
    answer=s.size();
    if(answer>nums.size()/2)
        answer=nums.size()/2;
    return answer;
}