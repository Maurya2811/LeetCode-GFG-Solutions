//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > &matrix, int n)
    {
       long long maxSum =0;
       int count =0;
       for(int i=0;i<n;i++){
           long long sum =0;
           for(int j=0;j<n;j++){
               sum+= matrix[i][j];
           }
           maxSum = max(maxSum,sum);
       }
        for(int i=0;i<n;i++){
           long long sum =0;
           for(int j=0;j<n;j++){
               sum+= matrix[j][i];
           }
           maxSum = max(maxSum,sum);
       }
        for(int i=0;i<n;i++){
           long long sum =0;
           for(int j=0;j<n;j++){
               sum+= matrix[j][i];
           }
           count += maxSum - sum;
       }
       
       return count;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends