//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{   private:
    bool isSafe(int row, int col,int grid[N][N],int val){
         for(int i=0;i<9;i++){
             if(grid[i][col]==val){
                 return false;
             }
             if(grid[row][i]==val){
                 return false;
             }
             if(grid[3*(row/3)+ i/3][3* (col/3)+ i%3]==val){
                 return false;
             }
         }
         return true;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
       for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(grid[row][col]==0)
                   {
                       for(int i=1;i<=9;i++){
                           if(isSafe(row,col,grid,i)){
                               grid[row][col]=i;
                              
                              if(SolveSudoku(grid)){
                                  return true;
                              }
                              grid[row][col]=0;
                           }
                       }
                      return false; 
                   }
            }
       }
       return true;
       
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
         for(int i=0;i<9;i++){
             for(int j=0;j<9;j++){
                 cout<<grid[i][j]<<" ";
             }
         } 
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends