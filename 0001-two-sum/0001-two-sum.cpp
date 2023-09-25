class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v1(2);
        for(int i=0;i<nums.size();i++){
          for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
            v1[0]=i;
            v1[1]=j;
            return v1;
            }
          }
        }
        return v1;
    }
};