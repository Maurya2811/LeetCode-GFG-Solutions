//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
      //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'

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