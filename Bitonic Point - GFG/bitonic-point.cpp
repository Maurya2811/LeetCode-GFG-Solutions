//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
              
              int s=0, e = n-1;
              
              while(s<=e){
                  int mid = s + (e-s)/2;
                  
                  if(mid>0 && arr[mid]>arr[mid-1] && mid+1<n && arr[mid]>arr[mid+1])
                  return arr[mid];
                  
                  else if(mid>0 && arr[mid]>arr[mid-1]){
                      s =  mid+1;
                  }else if(mid+1<n && arr[mid]>arr[mid+1]){
                      e= mid-1;
                  }
                  else if(mid == 0){
                      if(arr[0]>arr[1])
                      return arr[0];
                      else 
                      return arr[1];
                  }else if(mid==n-1){
                      if(arr[n-1]>arr[n-2])
                      return arr[n-1];
                      else 
                      return arr[n-2];
                  }
              }
              
            //   return -1;
              return arr[e]; 
            // when (s<e)
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends