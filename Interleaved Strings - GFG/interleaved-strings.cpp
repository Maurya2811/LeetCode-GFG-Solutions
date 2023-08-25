//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
  // We are reducing the Problem into two variable by using the 
  // Observation that i+j always equals to k;
     int n,m,N;
     
     int dp[101][101];
     
    bool solve(int i, int j, string &a, string &b, string &c){
        if(i==n && j==m && i+j == N) // i+j = k;
        return true;
        
        if(i+j >=N){ // means that i<n but i+j 
            return false;
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        bool result = false;
       
        if( a[i]==c[i+j] ){
            result = solve(i+1,j,a,b,c);
        }
        if(result){
            return dp[i][j] = true;
        }
        
        if( b[j]==c[i+j] ){
            result = solve(i,j+1,a,b,c);
        }
        
        return dp[i][j] = result;
    }
    
    bool isInterleave(string &a, string &b, string &c) 
    {
      n= a.length(),m = b.length(), N= c.length();
      
      if(n+m != N)
      return false; 
    
      memset(dp,-1,sizeof(dp));
      return solve(0,0,a,b,c);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends