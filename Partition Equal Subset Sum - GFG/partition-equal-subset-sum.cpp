//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

  
  int solve(int idx,int arr[],int &N,int sum,  vector<vector<int>>& dp){
      if(sum==0)return 1;
      
      if(idx>=N || sum<0 )
      return 0;
      
      if(dp[idx][sum]!=-1)
      return dp[idx][sum];
      int ans1 = solve(idx+1,arr,N,sum-arr[idx],dp);
      int ans2 = solve(idx+1,arr,N,sum,dp);
      
      
      return dp[idx][sum] = (ans1 || ans2);
  }
    int equalPartition(int N, int arr[])
    {
        
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum&1){
            return 0;
        }
        int ans = sum/2;
        vector<vector<int>> dp(N+1,vector<int>(ans+1,-1));
        return solve(0,arr,N,ans,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends