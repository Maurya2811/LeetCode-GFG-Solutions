class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, string &s1, string &s2){
        if(i>=s1.length() && j>= s2.length())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i>=s1.length()){
            return dp[i][j]= 1+solve(i,j+1,s1,s2);
        }
        
        if(j>=s2.length()){
            return dp[i][j]= 1+solve(i+1,j,s1,s2);
        }
        
        int ans=0;
        if(s1[i]!=s2[j]){
            ans =  1+ min(solve(i+1,j,s1,s2), solve(i,j+1,s1,s2));
        }
        
        else{
            ans =solve(i+1,j+1,s1,s2);
        }
        return dp[i][j]= ans;
    }
    
    int minDistance(string word1, string word2) {
        
        memset(dp,-1,sizeof(dp));
       return solve(0,0,word1,word2);
    }
    
};