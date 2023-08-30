//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     const int MOD = 1e9+7;
     
     
    int countSubsetSum( vector<int>& arr, int &n , int &sum){
        
        vector<vector<int>> t(n+1, vector<int>(sum+1));
        
        for(int j=0;j<sum+1;j++){
            t[0][j]=0;
        }
        for(int i=0;i<n+1;i++){
             t[i][0]=1;
        }
        
        // Since 0 is also the part of our arr
        // so we will start 2nd loop from 0 ;
        
        // t[n][sum] == t[i][j]
        //   n  -> i
        //   sum -> j
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                
                if(arr[i-1]<=j){
                    t[i][j] = ( t[i-1][j-arr[i-1]] + t[i-1][j] )%MOD ;
                }
                else
                    t[i][j] =  ( t[i-1][j]) %MOD;
            }
        }
        
        return t[n][sum]%MOD;
    }
  
        //  sum(s1 subset) + sum(s2 subset) = Total Array Sum
        //  sum(s1 subset) - sum(s2 subset) = d (given)
        //         +
       //   ------------------------------------------------------
       //     2* sum(s1 subset) = Total Array Sum + d
      // ==>    sum(s1 subset) = (Total Array Sum + d)/2;
      
      
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
             if((totalSum+ d)&1){
                 return 0;
             }
             
        int sum = (totalSum + d )>>1;
        
        
       return countSubsetSum(arr,n,sum);
        
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends