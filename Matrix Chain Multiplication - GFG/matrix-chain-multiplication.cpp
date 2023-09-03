//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int t[101][101];
   int solve(int i, int j, int arr[]){
       if(i>=j){
           return 0;
       }
       
       if(t[i][j]!=-1)
       return t[i][j];
       
       int mini = INT_MAX;
       
       for(int k=i+1;k<=j;k++){
           
           int temp = solve(i,k-1,arr) + solve(k,j,arr) + (arr[i-1]*arr[k-1]*arr[j]);
           
           mini = min(temp,mini);
           
       }
       
       return t[i][j]= mini;
   }
    int matrixMultiplication(int N, int arr[])
    {
       if(N==2){
           return 0;
       }
       memset(t,-1,sizeof(t));
       return solve(1,N-1,arr);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends