class Solution {
public:
    int m,n;
    
    bool solve(int i, int j, string &s, string &t,vector<vector<int>> &dp){
        if(i>=m)
            return true;
        if(j>=n)
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans1 = false;
        bool ans2 = false;
        
        
        if(s[i]==t[j]){
            ans1 = solve(i+1,j+1,s,t,dp);
            if(ans1)
                return dp[i][j] = true;
        }
          
        else{
          ans2 = solve(i,j+1,s,t,dp);
        }
        
        return dp[i][j] = (ans1 | ans2) ;
    }
    
    bool isSubsequence(string s, string t) {
        m=s.length();
        n=t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,s,t,dp);
    }
};