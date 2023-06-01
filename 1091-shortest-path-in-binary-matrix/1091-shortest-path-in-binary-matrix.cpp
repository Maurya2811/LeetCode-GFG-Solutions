class Solution {
public:
    vector<pair<int,int>> directions {
                                       {0,1},{1,0},{1,1},{-1,-1},
                                      {1,-1},{-1,1},{-1,0},{0,-1}
                                     };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        
       
    
        if(m==0 || n==0 || grid[0][0]==1)
            return -1;
        
          auto isSafe = [&](int x,int y){
        return x<m && y<n && x>=0 && y>=0;
        };
        
        queue<pair<int,int>> que;
        
        que.push({0,0});
        grid[0][0]=1;
        
        int level=0;
        
        while(!que.empty()){
            int N=que.size();
            while(N--){
              auto curr = que.front();
            int x = curr.first;
            int y = curr.second;
               que.pop();
            
            if(x== m-1 && y ==n-1){
                return level+1;
            }
            
            for(auto dir: directions){
                int x_ = x+dir.first;
                int y_ = y+dir.second;
            
            if(isSafe(x_,y_) && grid[x_][y_]==0){
                que.push({x_,y_});
                grid[x_][y_]=1;
            }
          }
        }
            level++;
    }
         return -1;
    }
};