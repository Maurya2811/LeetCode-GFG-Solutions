class Solution {
public:
    int m,n;
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]==1)
            return  0;
        if(i==m-1 && j==n-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right = solve(i,j+1,grid);
        int down = solve(i+1,j,grid);
        
        
        return dp[i][j]= right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        memset(dp,-1,sizeof(dp));
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return solve(0,0,obstacleGrid);
    }
};