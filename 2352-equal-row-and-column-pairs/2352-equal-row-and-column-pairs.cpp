class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        bool flag = true;
       int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                flag = true;
                for(int k=0;k<n;k++){
                    if(grid[i][k]!=grid[k][j]){
                        flag = false;
                    }
                }
                if(flag){
                    count++;
                }
            }
        }
        return count;
    }
};