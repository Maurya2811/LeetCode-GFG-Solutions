/*
    NOTE : This problem is similar to Leetcode-329.
           Leetcode-329 is a famous interview problem so this is kind of standard problem.
           That's why I always say, don't be afraid of new Hard Problems,these qns are standard and many other problems can
           be solved using the concept based on these problems.
*/

//-------In future, I will move this qn to a separate folder "2D-DP"

//Approach-1 (Using simple DFS) - TLE
class Solution {
public:
     int t[1001][1001];
    int m, n;
    vector<vector<int>> directions = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    long long MOD = 1e9+7;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(t[i][j]!=-1)
            return t[i][j];
        int answer = 1;
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(isSafe(i_, j_) && grid[i_][j_] < grid[i][j]) {
                answer = (answer + dfs(grid, i_, j_)) % MOD;
            }
        }
        
        return t[i][j]=answer;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
          memset(t, -1, sizeof(t));
        int result = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                result = (result + dfs(grid, i, j)) % MOD;
                
            }
        }
        
        
        return result;
    }
};