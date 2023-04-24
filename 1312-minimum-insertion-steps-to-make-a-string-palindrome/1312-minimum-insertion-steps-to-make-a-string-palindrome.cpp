class Solution {
public:
    int dp[501][501];
        int solve(string &s,int i,int j){
            if(i>j)
               return 0; // All req. chars are inserted
            if(dp[i][j]!=-1)
                return dp[i][j];
            if(s[i]==s[j])
              return dp[i][j]=solve(s,i+1,j-1);
           else 
                // Char is inserted in two possible ways
               return dp[i][j]= 1 + min (solve(s,i,j-1) ,solve(s,i+1,j)); 
//   1 is added bcoz one char is inserted ,, at before i index     2. after j index that's why j index is not updated       
        }
    int minInsertions(string s) {
       memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};