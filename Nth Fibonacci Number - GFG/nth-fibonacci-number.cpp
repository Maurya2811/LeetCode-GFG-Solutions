//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    const int mod = 1e9+7 ;
    int nthFibonacci(int n){
        
        if(n==1)
        return 0;
        if(n==2)
        return 1;
        
        long long int first=0,second =1;
        long long int sum=0;
        
        while(n>1){
            sum = (first+second)%mod;
            first = second;
            second = sum%mod;
            n--;
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends