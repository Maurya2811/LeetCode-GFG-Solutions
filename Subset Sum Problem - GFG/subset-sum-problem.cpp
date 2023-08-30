//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

// Recursion + Memorsation 

/*
class Solution{   
public:

   
   bool solve(vector<int>& arr,int sum, int n,vector<vector<int>> &t){
       if(n==0 && sum==0 )
          return true;
       if(n==0 && sum!=0 ){
           return false;
       }      
         
         if(t[n][sum]!=-1){
             return t[n][sum];
         }
          
    if(arr[n-1]<= sum){
        return t[n][sum] = solve(arr,sum-arr[n-1],n-1,t) || solve(arr,sum,n-1,t);
    } 
    
    return t[n][sum] =  solve(arr,sum,n-1,t);
    
   }
   
    bool isSubsetSum(vector<int>&arr, int &sum){
          int n=arr.size();
          if(n==0 && sum==0 )
          return true;
       if(n==0 && sum!=0 )
           return false;
           
           vector<vector<int>> t (n+1,vector<int>(sum+1,-1));
       
    //   memset(t,-1,sizeof(t));
          return solve(arr,sum,n,t);
    }
};

*/

// Using TopDown Approach
class Solution{   
public:

   
   
    bool isSubsetSum(vector<int>&arr, int &sum){
          int n=arr.size();
          if(n==0 && sum==0 )
          return true;
          if(n==0 && sum!=0 )
           return false;
           
           bool t[n+1][sum+1] ;
           
           // initialization
          
          for( int j=0;j<sum+1 ;j++){
              t[0][j] = false;
          }
          for( int i=0;i<n+1 ;i++){
              t[i][0] = true;
          }
          
        //   t[n][sum] = t[i][j]
          for(int i=1;i< n+1 ;i++){
              for(int j=1;j< sum+1;j++){
                  if(j>= arr[i-1]){
                      t[i][j]  =  t[i-1][j-arr[i-1]] || t[i-1][j];
                  }else{
                      t[i][j] = t[i-1][j];
                  }
              }
          }
   
          return t[n][sum];
    }
};




//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends