class Solution {
public:
    int maxSubArray(vector<int>& nums) {
             // Kadane's Algorithm
            int sum=0;
          int maxSum=nums[0]; // Given that nums contains minimum one element
          for(int i=0;i<nums.size();i++){
                sum+=nums[i];
              maxSum = max(sum,maxSum);
              if(sum<0){ 
                 sum=0;
              }
          }
        return maxSum;
    }
};