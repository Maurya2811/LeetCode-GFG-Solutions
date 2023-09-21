//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    // int ans=0;
    
    int solve(int idx,int arr[], int &n,vector<int> &dp){
        if(idx>=n){
            // ans = max(ans,sum);
            return 0 ;
        }
        
        if(dp[idx]!=-1)
        return dp[idx];
        
     int ans1 =  arr[idx]+ solve(idx+2,arr,n,dp);
     int ans2 =            solve(idx+1,arr,n,dp);
     
     return dp[idx]= max(ans1,ans2);
    }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        
        vector<int> dp(n+1,-1);
       return solve(0,arr,n,dp);
        // return ans ;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends