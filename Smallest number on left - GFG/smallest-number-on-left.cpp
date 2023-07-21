//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
       
        vector<int>ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty())
                 ans[i]=-1;
           else if(arr[i]>st.top()){
               ans[i]=st.top();
           }
           else{
               while(!st.empty() && st.top()>=arr[i]){
                   st.pop();
               }
               if(st.empty()){
                   ans[i]=-1;
               }else{
                   ans[i]=st.top();
               }
           }
           st.push(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends