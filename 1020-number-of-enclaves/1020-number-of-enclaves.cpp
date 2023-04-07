class Solution {
public:
    
    // We have to find the no. of land nodes ,
    // through which we can't move to the OuOfbound or On Boundary
    
     int m,n;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
            return ;
       // Mark Visited 
        grid[i][j]=0;
        
         dfs(grid,i+1,j);  // Bottom 
         dfs(grid,i-1,j);  // Top
         dfs(grid,i,j+1);  // Right
         dfs(grid,i,j-1);  // Left
    }
   
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
         
      // Sare Boundary points par dfs maarna hai
        
        // First Col and Last Col pr DFS
        for(int row=0;row<m;row++){
            // Frist Col
            if(grid[row][0]==1){
                dfs(grid,row,0);
            }
            //Last Col
            if(grid[row][n-1]==1){
                dfs(grid,row,n-1);
            }
        }
        // First row and Last row pr DFS
        for(int col=0;col<n;col++){
            // Frist row
            if(grid[0][col]==1){
                dfs(grid,0,col);
            }
            //Last row
            if(grid[m-1][col]==1){
                dfs(grid,m-1,col);
            }
        }
         int count=0;
        // Count no. of 1's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if (grid[i][j]==1)
                count ++;
            }
        }
        return count;
    }
};