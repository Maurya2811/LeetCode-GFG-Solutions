//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Recursion + Memorisation 

/*
class Solution
{
    public:
    
      int  t[1001][1001];
      
      int solve(int W, int wt[], int val[], int n){
         
          if(n==0 || W==0)
           return 0;
           
           if(t[W][n]!=-1){
               return t[W][n];
           }
           
       if(W>=wt[n-1]){
           return t[W][n]= max(val[n-1] + solve(W-wt[n-1],wt,val,n-1) , solve(W,wt,val,n-1));
       }
       
       else 
       return t[W][n]= solve(W,wt,val,n-1);
       
      }
      
      
    int knapSack(int W, int wt[], int val[], int n) 
    { 
          if(n==0 || W==0)
           return 0;
           
          memset(t,-1,sizeof(t));
          
          return solve(W,wt,val,n);
       
    }
};
*/

//  Bottom Up Approach

class Solution
{
    public:
   
    int knapSack(int W, int wt[], int val[], int n) 
    { 
          if(n==0 || W==0)
           return 0;
           
            int  t[n+1][W+1] ;
        
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }  
         for(int j=0;j<W+1;j++){
            t[0][j]=0;
        }  
       
       // t[n][W] = t[i][j]
       
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               if(j>= wt[i-1])
               t[i][j] = max(val[i-1]+(t[i-1][j-wt[i-1]]) , t[i-1][j]);
               else{
                   t[i][j] = t[i-1][j];
               }
           }
       }
        
       
       return t[n][W];
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends