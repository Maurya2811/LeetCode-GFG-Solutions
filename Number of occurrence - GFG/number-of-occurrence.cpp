//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

   int upperBound (int arr[],int &n, int x){
        int s=0,e = n-1;
        int ans =-1;
        
        while(s<=e){
            int mid = s+ (e-s)/2;
            
            if(arr[mid]<= x){
                if(arr[mid]==x){
                    ans = mid;
                }
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
   }
    int lowerBound (int arr[],int &n, int x){
        int s=0,e = n-1;
        int ans =-1;
        
        while(s<=e){
            int mid = s+ (e-s)/2;
            
             if(arr[mid]==x){
                    ans = mid;
                    e = mid-1 ;
                }
            else if(arr[mid]< x){
                 s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
   }
    
	int count(int arr[], int n, int x) {
	     if(n==1){
	         return arr[0]==x ? 1: 0;
	     }
	     
	     int left = lowerBound(arr,n,x);
	     
	     if(left == -1){
	         return 0;
	     }
	     int right = upperBound(arr,n,x);
	     
	     return right - left +1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends