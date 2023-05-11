class Solution {
public:
    int m,n;
    int solve(int i,int j,vector<int> &nums1 , vector<int> &nums2,vector<vector<int>> &dp){
        if(i>=m || j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(nums1[i]==nums2[j])
            return dp[i][j]= 1+ solve(i+1,j+1,nums1,nums2,dp);
        else{
            return dp[i][j]=max(solve(i+1,j,nums1,nums2,dp),solve(i,j+1,nums1,nums2,dp));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
          m=nums1.size();
        n=nums2.size();
       vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,nums1,nums2,dp);
        
    }
};