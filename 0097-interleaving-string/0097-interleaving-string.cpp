class Solution {
public:
    int n,m,N; 
    int dp[101][101];
    bool solve(int i, int j, string &s1, string &s2, string &s3){
        if(i==n && j==m && i+j == N){
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i+j >= N)
            return dp[i][j] =  false;
        
        bool result = false;
        if(s1[i]==s3[i+j]){
             result = solve(i+1,j,s1,s2,s3);
        }
        if(result)
            return  dp[i][j] = result;
        if(s2[j]==s3[i+j]){
            result = solve(i,j+1,s1,s2,s3);
        }
        
        return dp[i][j] = result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        N = s3.length();
        
        if(n+m!=N)
            return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2,s3);
    }
};