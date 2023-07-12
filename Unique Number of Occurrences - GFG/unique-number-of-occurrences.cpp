//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    unordered_map<int,int> freq;
    
    void calFreq(int n, int arr[]){
        
         for(int i=0;i<n;i++){
             freq[arr[i]]++;
         }
    }
    
    bool isFrequencyUnique(int n, int arr[])
    {
        calFreq(n,arr);
        set<int> st;
         
         for(auto x:freq){
             st.insert(x.second);
         }
         
         
         return st.size()!=freq.size() ? false: true;
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends