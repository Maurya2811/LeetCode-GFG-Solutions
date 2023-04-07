class Solution {
public:
    int row , col;
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i>=row || i<0 || j>=col || j<0){
            return false;
        }
         if(grid[i][j]==1)
            return true;
        
        grid[i][j]=1;
        bool left_side =dfs(grid,i,j-1); // left
        bool right_side =dfs(grid,i,j+1);  // right
        bool up_side =dfs(grid,i-1,j);  // up
        bool down_side= dfs(grid,i+1,j);  // down
        
        return (left_side && right_side && up_side && down_side);
    }    
    
    int closedIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int count =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0)
                if(dfs(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};