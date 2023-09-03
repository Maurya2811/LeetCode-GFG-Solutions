//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   int t[205][205][2];

  int solve(int i, int j, string &s, bool isTrue ){
      if(i>j){
          return false;
      }
      if(t[i][j][isTrue]!=-1){
          return t[i][j][isTrue]%1003;
      }
      if(i==j){
          if(isTrue){
              return s[i]=='T';
          }else
          return s[i]=='F';
      }
      
      
      int ans = 0;
      for(int k=i+1;k<=j-1;k+=2){
          
          
          int leftTrue = t[i][k-1][true]!=-1 ? t[i][k-1][true]: solve(i,k-1,s,true);
          int leftFalse =  t[i][k-1][false]!=-1 ? t[i][k-1][false]:solve(i,k-1,s,false);
          int rightTrue  = t[k+1][j][true]!=-1 ? t[k+1][j][true]: solve(k+1,j,s,true);
          int rightFalse =  t[k+1][j][false]!=-1 ? t[k+1][j][false]:solve(k+1,j,s,false);
        //   int leftTrue =solve(i,k-1,s,true);
        //   int leftFalse =  solve(i,k-1,s,false);
        //   int rightTrue  =solve(k+1,j,s,true);
        //   int rightFalse =  solve(k+1,j,s,false);
          
          
          if(s[k]=='&'){
              if(isTrue){
                  ans+= leftTrue*rightTrue;
              }else{
                  ans+= leftFalse*rightTrue + leftTrue*rightFalse + leftFalse*rightFalse;
              }
          }
          else if(s[k]=='|'){
              if(isTrue){
                  ans+= leftFalse*rightTrue + leftTrue*rightFalse + leftTrue*rightTrue;
              }else{
                  ans+=  leftFalse*rightFalse;
              }
          }else{
              if(isTrue){
                  ans+= leftFalse*rightTrue + leftTrue*rightFalse ;
              }else{
                  ans+=  leftFalse*rightFalse + leftTrue*rightTrue;
              }
          }
      }
      return t[i][j][isTrue] = (ans%1003);
      
      
  }
    int countWays(int N, string S){
        if(N==1){
            if(S[0]=='F')
            return 0;
            return 1;
        }
        
        memset(t,-1,sizeof(t));
        
        return solve(0,N-1,S,true)%1003;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends