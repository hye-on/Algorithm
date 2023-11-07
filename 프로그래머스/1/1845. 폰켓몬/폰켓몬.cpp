#include <vector>
#include <iostream>
using namespace std;

bool n[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    int select_number=0;
    int pick_size = nums.size()/2;
    int nums_size = nums.size();
    int max_index=0;
    for(int i=0; i<nums_size ;i++){
      
        n[nums[i]]=true;
        if(nums[i]>max_index)
            max_index=nums[i];
    }
  
    for(int i=1;i<=max_index  ; i++){
        if(n[i])
            select_number++;
        if(select_number==pick_size)
            break;
        
    }

    answer=select_number;
    
    return answer;
}