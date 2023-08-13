class Solution {
public:
    
    int n;
    
    bool solve(int idx,vector<int> & nums,vector<int>&dp){
        if(idx>= n)
            return true;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        bool rule1=false, rule2=false,rule3=false;
        if(idx+1<n){
             if(nums[idx]==nums[idx+1]){
                 rule1= solve(idx+2,nums,dp);
                 if(rule1)
                     return true;
             }
            
          if(idx+2<n) { 
              if(nums[idx]==nums[idx+1] && nums[idx]==nums[idx+2]){
                 rule2= solve(idx+3,nums,dp);
                  if(rule2)
                     return true;
               }
             if(nums[idx]+1==nums[idx+1] && nums[idx]+2==nums[idx+2]){
                rule3= solve(idx+3,nums,dp);
                 if(rule3)
                     return true;
            }
            }
            return dp[idx] = (rule1 || rule2 || rule3) ;
        }
        return dp[idx] =false;
    }
    
    bool validPartition(vector<int>& nums) {
         
        n= nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};