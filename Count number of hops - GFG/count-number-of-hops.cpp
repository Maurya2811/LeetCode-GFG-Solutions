//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
  
      
     typedef long long ll ;
     
     const int MOD = 1e9+7;
      
      ll solve(int step, int n,vector<int> &dp){
          if(step==n){
              return 1;
          }
          if(step>n){
              return 0;
          }
          
          if(dp[step]!=-1)
          return dp[step];
          
          ll step1 = solve(step+1,n,dp);
          ll step2 = solve(step+2,n,dp);
          ll step3 = solve(step+3,n,dp);
          
          return dp[step]= (step1+step2+step3)%MOD;
      }
      
    long long countWays(int n)
    {
        
        if(n==1)
        return n;
        vector<int>dp(n+1,-1);
        return solve(0,n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends