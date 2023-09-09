// Recursion + Memoization
/*
class Solution {
public:
    
    int dp[1001];
    int solve(vector<int>& nums, int target){
         if(target==0)
           return 1;
      
      if(dp[target]!=-1)
          return dp[target];
        
        int ans=0;
      for(int &x: nums){
          if(target>=x)
         ans += solve(nums,target-x);
      } 
          dp[target]=ans;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
       return solve(nums,target);
  
    }
};
*/
    
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         //
//             vector<uint>dp(target+1,0);
        
//          dp[0]=1;    
//         for(int i=1;i<=target;i++){
//             for(int j=0;j<nums.size();j++){
//                 if(i>=nums[j])
//                 dp[i] += dp[i-nums[j]];
//             }
//         }
//         return dp[target];
//     }
// };

class Solution {
public:
    
    int dp[201][1001];
    int solve(int idx,vector<int> &nums,int target){
        
        if(target ==0)
            return 1;
        if(target<0)
            return 0;
        if(idx>= nums.size())
            return 0;
        
        if(dp[idx][target]!=-1)return dp[idx][target];
        
        // int not_take = solve(idx+1,nums,target);
        
        // int take  = solve(0,nums,target-nums[idx]);
        
        return dp[idx][target] = (solve(idx+1,nums,target) + solve(0,nums,target-nums[idx]));
    }
    int combinationSum4(vector<int>& nums, int target) {
        //
        memset(dp,-1,sizeof(dp));
           return solve(0,nums,target);
    }
};