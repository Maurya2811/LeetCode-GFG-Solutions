//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	   
	   int s=0, e= n-1;
	   
	   while(s<=e){
	       
	       int mid=(s+e)/2;
	       
	       if(mid+1<n && arr[mid]!=arr[mid+1] && mid>0 && arr[mid]!=arr[mid-1]){
	           return arr[mid];
	       }
	       else if(mid+1<n && arr[mid]==arr[mid+1] ){
	           if(mid%2==0)
	             s=mid+1;
	           else
	             e=mid-1;
	       }
	   //   else if(mid>0 && arr[mid]==arr[mid-1]){
	      else{
	           if(mid%2==1)
	               s=mid+1;
	           else
	               e=mid-1;
	      }
	   }
	    
	    return arr[s];
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends