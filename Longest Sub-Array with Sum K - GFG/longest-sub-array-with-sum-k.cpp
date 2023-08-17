//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        long long sum = 0;
        unordered_map<long long , int> mp;
        int maxi = 0;
        int j=0,i=0;
        while(j<n){
            sum += arr[j];
            // while(sum>k){
            //     sum -= arr[i];
            //     i++;
            // }
            if(sum == k){
                maxi = max(maxi,j-i+1);
            }
            // if(mp.find(sum-k)!=mp.end()){
            //     maxi = max(maxi, j - mp[sum-k] );
            // }
              if(mp.find(sum-k)!=mp.end())      {
                int len=j-mp[sum-k];
                if(len>maxi) maxi=len;
            }
            if(mp.find(sum)==mp.end())
            mp[sum]=j;
            
            j++;
        }
       return maxi; 
    } 

};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends