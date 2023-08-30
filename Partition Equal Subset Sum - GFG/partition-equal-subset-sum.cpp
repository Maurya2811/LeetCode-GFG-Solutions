//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

  bool subsetSum(int n, int arr[], int sum){
      
      if(n==0 && sum ==0 )
      return true;
      
      bool t[n+1][sum+1];
      
      // Initialization
      
      for(int j=0;j<sum+1;j++){
          t[0][j]=false;
      }
      
      for(int i=0;i<n+1;i++){
          t[i][0]=true;
      }
      
      
      // tabulation
      
      // t[n][sum] == t[i][j]
      
      for(int i=1;i<n+1;i++){
          for(int j=1;j<sum+1 ; j++){
              if(j>= arr[i-1]){
                  t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
              }else
               t[i][j] =  t[i-1][j];
          }
      }
      
      return t[n][sum];
  }
  
  
    int equalPartition(int N, int arr[])
    {
        int totalSum =0;
        
     totalSum =  accumulate(arr,arr+N,0);
     
        if((totalSum & 1)==1){
            return 0;
        }
        
        return subsetSum(N,arr,totalSum>>1);
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