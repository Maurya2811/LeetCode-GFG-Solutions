//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 vector<vector<int> > ans;
 
   unordered_map<int,bool> colCheck;
    unordered_map<int,bool> upperLeftDiagnolCheck;
    unordered_map<int,bool> upperRightDiagnolCheck;
   
    void storeSolution(vector<vector<char>> &board, int n) {
        vector<int > temp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n ;j++) {
                if(board[i][j]=='Q')
                temp.push_back(j+1);
            }
        }
        ans.push_back(temp);
    }
    
     bool isSafe(int row, int col, vector<vector<char>> &board, int n) {

        if(colCheck[col] == true )
            return false;
            
        if(upperLeftDiagnolCheck[n+col-row] == true)
            return false;
            
        if(upperRightDiagnolCheck[row+col] == true)
            return false;

        return true;


	
  //check karna chahte h , k kya main 
  //current cell [row,col] pr    QUEEN rakh 
  //sakta hu ya nahi
  // int i = row;
  // int j = col;

  // //check row
  // while(j >= 0) {
  //   if(board[i][j] == 'Q') {
  //     return false;
  //   }
  //   j--;
  // }

  // //check upper left diaglnol 
  // i = row;
  // j = col;
  // while(i>=0 && j>=0 ) {
  //   if(board[i][j] == 'Q'){
  //     return false;
  //   }
  //   i--;
  //   j--;
  // }


  // //check bottom left diagnol
  // i = row;
  // j = col;
  // while( i < n && j >=0) {
  //   if(board[i][j] == 'Q') {
  //     return false;
  //   }
  //   i++;
  //   j--;
  // }

  // //kahin pr bhi queen nahi mili
  // //iska matlab ye position safe hai 
  // //iska matlab eturn kardo true
  // return true;   
}
   void solve(vector<vector<char>> &board, int row, int n  ) {
    //base case
    if(row >= n) {
        storeSolution(board, n);
        return ;
    }

    //1 case solve karna h , baaki recursion sambhal lega

    for(int col = 0; col <n; col++) {
        if(isSafe(row, col, board, n)) {
        //rakh do
        board[row][col] = 'Q';
        colCheck[col] = true;
        upperLeftDiagnolCheck[n+col-row] = true;
        upperRightDiagnolCheck[row+col] = true;
            
        //recursion solution laega
        solve(board, row+1, n);
        //backtracking
        board[row][col] = '.';
        colCheck[col] = false;
        upperLeftDiagnolCheck[n+col-row] = false;
        upperRightDiagnolCheck[row+col] = false;
        }

    }
}
  
    vector<vector<int>> nQueen(int n) {
     vector<vector<char>> board(n, vector<char>(n,'.'));
       
        int row = 0;
        solve(board, row, n);
        // reverse(ans.begin(),ans.end());
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends