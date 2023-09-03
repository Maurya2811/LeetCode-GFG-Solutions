//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
public:
   
   int N,M;

    void DFS(int i, int j ,vector<vector<char>> &mat ){
        if(i>=N || i<0 || j>=M || j<0 || mat[i][j]!='O'){
            return;
        }
        mat[i][j]='#';
        
        DFS(i,j+1,mat);
        DFS(i,j-1,mat);
        DFS(i+1,j,mat);
        DFS(i-1,j,mat);
        return;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
       // N = row  & M = col
       N = n  , M = m;
       
       for(int i=0;i<n;i++){
           if(mat[i][0]=='O'){
               DFS(i,0,mat);
           }
           if(mat[i][m-1]=='O'){
               DFS(i,m-1,mat);
           }
       }
       
       for(int i=0;i<m;i++){
           if(mat[0][i]=='O'){
               DFS(0,i,mat);
           }
           if(mat[n-1][i]=='O'){
               DFS(n-1,i,mat);
           }
       }
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]=='O'){
                   mat[i][j]='X';
              }
              else if(mat[i][j]=='#'){
                   mat[i][j]='O';
               }
           }
       }
       return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends