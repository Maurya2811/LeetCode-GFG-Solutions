//Approach-1 (Recursion + Memo)
//Recursion T.C : O(2^(m*n))
//Memo T.C      : O(m*n)
class Solution {
public:
    int m, n;
    int t[101][101];
    
    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        
        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(i == m-1 && j == n-1)
            return 1;
        
        //Why we are not making [i][j] visited ?
        //Because robot can only move down or right so it will never visit any visited cell again
        //int temp = obstacleGrid[i][j];
        //obstacleGrid[i][j] = -1;
        
        int right = solve(obstacleGrid, i, j+1);
        int down  = solve(obstacleGrid, i+1, j);
        
        //obstacleGrid[i][j] = temp;
        
        return t[i][j] = right + down;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        memset(t, -1, sizeof(t));
        
        return solve(obstacleGrid, 0, 0);
    }
};