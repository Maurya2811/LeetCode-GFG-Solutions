class Solution {
public:
    unordered_map<int,bool> rowCheck;
  unordered_map<int,bool> upper_left_diagonal;
  unordered_map<int,bool> lower_left_diagonal;
           vector<vector<string>> ans;

    // Storing Solution
    
    void storeSolution(int &n,vector<vector<char>> &board){
        vector<string>output;
        string temp;
        for(int i=0;i<n;i++){
            temp="";
          for(int j=0;j<n;j++){
              temp.push_back(board[i][j]);
          }
        output.push_back(temp);
      }
        ans.push_back(output);
    }
    
        
   // Function to Check whether Queen is in Attacking position or not     
    bool isSafe(int row,int col,int &n)
   {
     if(rowCheck[row]==true){
         return false;
     }
     if(upper_left_diagonal[n+col-row]==true){
         return false;
     }
     if(lower_left_diagonal[col+row]==true){
         return false;
     }
     /*
     check karna chahte h , k kya main 
     current cell [row,col] pr    QUEEN rakh 
       int i=row;
       int j=col;
       
       // ROW CHECK
     while(j>=0){
          if(chess[i][j]=='Q'){
              return false;
          }
          j--;
      }
      
      i=row;
      j=col;
      
       // upper_left_diagonal CHECK
      while(j>=0 && i>=0){
          if(chess[i][j]=='Q'){
              return false;
          }
          j--;
          i--;
      }
      
      i=row;
      j=col;
      
        // lower_left_diagonal CHECK
      while(j>=0 && i<n){
          if(chess[i][j]=='Q'){
              return false;
          }
          i++;
          j--;
      }
      kahin pr bhi queen nahi mili
      iska matlab ye position safe hai 
      iska matlab return kardo true
      */
      return true;
  }
    void solveQueen(vector<vector<char>> &board,int &n,int col){
        if(col>=n){
         storeSolution(n,board);  
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n)){
                rowCheck[row]=true;
                upper_left_diagonal[n+col-row]=true;
                lower_left_diagonal[col+row]=true;
                board[row][col]='Q';
                solveQueen(board,n,col+1);
                
                // BACKTRACKING
                  board[row][col]='.';
                  rowCheck[row]=false;
                  upper_left_diagonal[n+col-row]=false;
                  lower_left_diagonal[col+row]=false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.')); 
         solveQueen(board,n,0);
        return ans;
    }
};