class Solution {
public:
//    USING DP
    /*
    int memory[201][201];
    
    int solve(vector<vector<int>>& grid,int i,int j,int &m,int &n){
        if(i==m-1 && j==n-1){
             return grid[i][j];
        }
        if(memory[i][j]!=-1)
            return memory[i][j];
         if(i==m-1){ //Only go right
            return memory[i][j]= grid[i][j] + solve(grid,i,j+1,m,n);
        }
        else if(j==n-1){ // Only go down
            return memory[i][j]=  grid[i][j]+solve(grid,i+1,j,m,n);
      }
        else{
            return memory[i][j]= grid[i][j] + min(solve(grid,i+1,j,m,n),solve(grid,i,j+1,m,n));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
         int n=grid[0].size();
        memset(memory,-1,sizeof(memory));
        return solve(grid,0,0,m,n);
    }
    */
     int minPathSum(vector<vector<int>>& grid) {
          int m=grid.size();
         int n=grid[0].size();
         
         vector<vector<int>> temp(m,vector<int>(n));
            temp[0][0]=grid[0][0];
         
         // Filling First Row
         
         for(int col=1;col<n;col++){
             temp[0][col]=grid[0][col] + temp[0][col-1];
         }
         
         // Filling First Column
         
         for(int row=1;row<m;row++){
             temp[row][0]=grid[row][0] + temp[row-1][0];
         }
         
         // Filling rest of the cells
         
         for(int i=1;i<m;i++){
             for(int j=1;j<n;j++){
                 
                 temp[i][j]  = grid[i][j] + min(temp[i-1][j],temp[i][j-1]);
               }
         }
         return temp[m-1][n-1];
     }
    
};