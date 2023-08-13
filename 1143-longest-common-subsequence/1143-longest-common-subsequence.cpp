// Recursion + Memorization
/*
class Solution {
public:
    int dp[1001][1001];
    int solve(int idx1,int idx2,string &s1,string &s2){
       
        if(idx1 <0 || idx2<0){
            return 0;
        }
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]= 1 + solve(idx1-1,idx2-1,s1,s2);
        }
        return dp[idx1][idx2]= max( solve(idx1-1,idx2,s1,s2),solve(idx1,idx2-1,s1,s2));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int  n1 = text1.length();
       int n2 = text2.length();
        memset(dp,-1,sizeof(dp));
        return solve(n1-1,n2-1,text1,text2);
    }
};
*/

// Bottom UP
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int  n1 = text1.length();
       int n2 = text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        
        for(int j=0;j<=n2;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
               if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};
