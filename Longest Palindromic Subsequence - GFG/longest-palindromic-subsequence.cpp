//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int n;
  int solve(int i,int j,string A,string s){
      vector<vector<int>> lcs(n+1,vector<int>(n+1));
      for(int i=0;i<=n;i++){
          lcs[0][i]=0;
          lcs[i][0]=0;
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              if(s[i-1]==A[j-1]){
                  lcs[i][j]=lcs[i-1][j-1]+1;
              }
              else{
                  lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
              }
          }
      }
      return lcs[n][n];
  }
    int longestPalinSubseq(string A) {
         string s = A;
          n=s.length();
         reverse(s.begin(),s.end());
         
          return solve(0,0,A,s);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends