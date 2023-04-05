//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
        
        //      !!!!  safe/valid move
        /*
            1. Index array ke bahar na jae
            2. Maze ka box me 1 hona chahiye
            3. Visited me false hona chahiye
        */
  
        
class Solution{
    public:
     
      bool isSafe(vector<vector<int>> &m,int& n,int x,int y,vector<vector<bool>> &visited) {
        if((x<n && x>=0) && (y>=0 && y<n ) && ( visited[x][y]==false) && (m[x][y]==1)){
         
        return true;
            
        }
        
        return false;
    }   
    void solveMaze(vector<vector<int>> &m,int &n,int x,int y,vector<string>&path ,
    vector<vector<bool>> &visited, string output ){
        // Base Case
        if(x==n-1 && y==n-1)
        {
            path.push_back(output);
            return ;
        }
        // Solve One case
        
        // left move
        if( isSafe(m,n,x,y-1,visited))
           {
               visited[x][y-1]=true;
               solveMaze(m,n,x,y-1,path,visited,output+'L');
               visited[x][y-1]=false;
           }
        
        // right move
        if( isSafe(m,n,x,y+1,visited))
           {
               visited[x][y+1]=true;
               solveMaze(m,n,x,y+1,path,visited,output+'R');
               visited[x][y+1]=false;
           }
        // up move
         if( isSafe(m,n,x-1,y,visited))
           {
               visited[x-1][y]=true;
               solveMaze(m,n,x-1,y,path,visited,output+'U');
               visited[x-1][y]=false;
           }
        // down move
         if(  isSafe(m,n,x+1,y,visited))
           {
               visited[x+1][y]=true;
               solveMaze(m,n,x+1,y,path,visited,output+'D');
               visited[x+1][y]=false;
           }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<string> path;
        vector<vector<bool>> visited(n,vector<bool>(n,false)); 
        visited[0][0]=true;
        
        //  No path Exists
        if(m[0][0]==0 || m[n-1][n-1]==0)
          return path;
       string output="";
      
       solveMaze(m,n,0,0,path,visited,output);
        return path;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends