class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j, string &s1, string&s2){
        if(i>=s1.length() && j>=s2.length()){
            return 0;
        }
        if(i>=s1.length())
            return s2[j]+solve(i,j+1,s1,s2);
        
        if(j>=s2.length())
            return s1[i]+solve(i+1,j,s1,s2);
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int sum = 0;
        
        if(s1[i]!=s2[j])
            sum = min(s1[i]+solve(i+1,j,s1,s2) , s2[j]+solve(i,j+1,s1,s2));
        
        else{
             sum = solve(i+1,j+1,s1,s2);
        }
        
        return dp[i][j]=sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,s1,s2);
    }
};