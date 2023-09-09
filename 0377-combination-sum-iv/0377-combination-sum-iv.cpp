class Solution {
public:
    
    // int ans =0;
    int n;
    int dp[1001];
    
    int solve(vector<int>& nums, int target){
    
         if(target==0){
           return 1;
        }
      if(dp[target]!=-1)
          return dp[target];
        
        int ans=0;
      for(int &x: nums){
          if(target>=x)
         ans += solve(nums,target-x);
      } 
         dp[target]=ans;
//         int ans1 = solve(nums,idx+1,sum,target) ;
//         int ans2= solve(nums,idx,sum+nums[idx],target);
//         int ans3 =solve(nums,idx+1,sum+nums[idx],target);
        
        // return ans1+ans2+ ans3;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp,-1,sizeof(dp));
      
        n= nums.size();
       return solve(nums,target);
  
    }
};