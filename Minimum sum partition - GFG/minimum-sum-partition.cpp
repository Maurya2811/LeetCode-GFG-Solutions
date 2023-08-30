//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
      
  public:
  
      int subsetSum(int arr[], int &n, int &Range ){
          
          bool t[n+1][Range+1];
          
          // Initialization
          for(int j=0;j<Range+1;j++){
              t[0][j]=false;
          }
          for(int i=0;i<n+1 ; i++){
              t[i][0]=true;
          }
          
          // t[n][sum] = t[i][j]
          for(int i=1;i<n+1;i++){
              for(int j=1;j<Range+1;j++){
                  if(arr[i-1]<=j){
                     t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                  }else
                   t[i][j] = t[i-1][j];
              }
          }
          
          // Now we want the last Row of the Matrix 
          // and only those elements whose value is True;
          // and we have to go only upto range/2;
          
           vector<int> nums;
           
           for(int j=0;j<=(Range)/2 ; j++){
               if(t[n][j])
                 nums.push_back(j);
           }
           
           int minDiff = INT_MAX;
           //   we have to minimize 
           // Range - 2(s1) 
          
          for(int i=0;i<nums.size();i++){
              
              minDiff = min(minDiff , Range-(2*nums[i]));
          }
          
          return minDiff;
      }
	int minDifference(int arr[], int n)  { 
	   
	      int Range = accumulate(arr,arr+n,0);
	      
	      return subsetSum(arr,n,Range) ;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends