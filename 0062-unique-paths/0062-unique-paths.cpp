/*
class Solution {
public:
    int ans=0;
    
    void solve(int i,int j,int &m,int &n){
        if(i>=n || j>=m){
            return ;
        }
        
        if(i==n-1 && j==m-1){
            ans ++;
            return ;
        }
        
        solve(i+1,j,m,n);
        solve(i,j+1,m,n);
        
    }
    int uniquePaths(int m, int n) {
         solve(0,0,m,n);
       
        return ans;
    }
};
*/
class Solution {
public:
   
    int dp[101][101];
    int solve(int i,int j,int &m,int &n){
        if(i>=n || j>=m){
            return dp[i][j]=0;
        }
        
        if(i==n-1 && j==m-1){
            
            return dp[i][j]=1;
        }
       if (dp[i][j]!=-1)
            return dp[i][j];
      return dp[i][j] = solve(i+1,j,m,n) +  solve(i,j+1,m,n);
       
        
    }
    int uniquePaths(int m, int n) {
        
        memset(dp,-1,sizeof(dp));
         return solve(0,0,m,n);
       
        // return ans;
    }
};
// 
//  