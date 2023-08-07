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
{
    public:
    
      bool isSafe(int row, int col, int board[N][N], int value) {
        int n =9;

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
   /*
            for Indexing
                         3*(row/3)+(i/3)
            
              3*(row/3) -> 0 , 3 , 6              
           *   i/3      ->         0   
                         +
                        -------------
                           0 , 3 , 6 
                           
               3*(row/3) -> 0 , 3 , 6
           *   i/3      ->          1   
                         +
                        ---------------
                            1 , 4 , 7  
                           
                           
               3*(row/3) -> 0 , 3 , 6
           *  i/3        ->         2   
                         +
                        -----------------
                            2 , 5 , 8           
                            
            
                           
  ===================================================================              
             FOR MOVEMENT 
                 3*(col/3)+(i%3)
                 
                 
               3*(col/3) -> 0 , 3 , 6         
           *   i%3       ->         0   
                         +
                        -------------
                           0 , 3 , 6 
                           
                           
               3*(col/3) -> 0 , 3 , 6
           *   i%3       ->         1   
                         +
                        ---------------
                            1 , 4 , 7  
                           
                           
               3*(col/3) -> 0 , 3 , 6
           *  i%3        ->         2   
                         +
                        -----------------
                            2 , 5 , 8       
                            
                            
  */         
              
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }
    
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int board[N][N])  
    { 
        int n = 9;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                //check for empty cell
                if(board[i][j] == 0) {
                    //try to fill with values ranging from 1 to 9
                    for(char val = 1; val<=9; val++) {
                        //check for safety
                        if(isSafe(i,j, board, val)) {
                            //insert
                            board[i][j] = val;
                            //recursion sambal lega
                            bool remainingBoardSolution = SolveSudoku(board);
                            if(remainingBoardSolution == true) {
                                return true;
                            }
                            else {
                                //backtrack
                                board[i][j] = 0;
                            }
                        }
                    }
                    //if 1 se 9 tak koi bhi value se solution
                    //nahi nikla ,current cell pr, 
                    //that means piche kahin pr galti h , 
                    //go back by returning false
                return false;
                }
            }
        }
        //all cells filled 
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               cout<<grid[i][j]<<" ";
           }
        //   if(i!=8){
        //       cout<<endl;
        //   }
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