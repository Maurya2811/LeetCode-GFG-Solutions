//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Using Kadanes Algorithm
class Solution{
    public:
    int maxOnes(int a[], int n)
    {
       int countZero = 0;
       int countOne  = 0;
       int maxZeroCount =0;
       
       for(int i=0;i<n;i++){
           if(a[i]==0){
               countZero++;
               maxZeroCount = max(countZero, maxZeroCount);
           }
           else{
               countOne++;
               countZero--;
               if(countZero<0){
                   countZero=0;
               }
           }
       }
       return countOne + maxZeroCount ;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends