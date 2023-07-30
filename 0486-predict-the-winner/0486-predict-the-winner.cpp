class Solution {
public:
    int dp[21][21];
    int solve(vector<int>& nums,int i,int j){
         int player2;
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int take_left = nums[i]+ min(solve(nums,i+2,j), solve(nums,i+1,j-1));
       int take_right = nums[j]+ min(solve(nums,i+1,j-1), solve(nums,i,j-2));
        
        int player1 = max(take_left,take_right);
        
        return dp[i][j]=player1;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
       int  player2 = accumulate(nums.begin(),nums.end(),0) ;
          int player1 = solve(nums,0,n-1);
        
        player2 = player2 - player1;
        
         return player1>= player2;
    }
};