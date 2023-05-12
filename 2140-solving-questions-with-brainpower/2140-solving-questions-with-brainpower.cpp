class Solution {
public:
    
    long long solve(vector<vector<int>>& questions,int i,vector<long long> &dp){
         
        if(i>=questions.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        // long long max=0;
         
        long long m1 = questions[i][0]+ solve(questions,i+questions[i][1]+1,dp);
        
        long long m2 = 0 + solve(questions,i+1,dp);
        
        return dp[i]=max(m1,m2);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
          vector<long long> dp(n+1,-1);
          
        return solve(questions,0 ,dp);
    }
};