class Solution {
public:
     bool isValid(vector<vector<char>>& board,char value,int row,int col){
         for(int i=0;i<9;i++){
             if(board[i][col]==value){
                 return false;
             }
              if(board[row][i]==value){
                 return false;
             }
             
              if(board[3*(row/3)+(i/3)][(3*(col/3))+(i%3)]==value)
                     return false;
                     
         }
      
         return true;
     }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char value='1';value<='9';value++){
                        if(isValid(board,value,i,j)){
                            board[i][j]=value;
                          bool aageKaSolution = solve(board);
                            if(aageKaSolution)
                                return true;
                            
                             board[i][j]='.';
                        }
                      
                           
                    }
                     return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};