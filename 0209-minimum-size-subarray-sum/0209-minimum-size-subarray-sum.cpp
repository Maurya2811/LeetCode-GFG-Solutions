class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0;
        int minLength=INT_MAX;
        int len=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[j++];
                   
                }
                len=i-j+2;
                minLength= min(minLength,len);
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};