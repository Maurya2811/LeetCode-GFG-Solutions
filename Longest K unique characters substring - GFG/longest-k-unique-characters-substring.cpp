//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
         int i=0,j=0;
         int arr[26]={0};
         int n = s.length();
         int maxi =-1;
         int uniqueCharCount =0;
         while(j<n){
             arr[s[j]-'a']++;
             if(arr[s[j]-'a']==1){
                 uniqueCharCount++;
             }
             if(uniqueCharCount==k){
                 maxi = max(maxi, j-i+1);
             }
             while(uniqueCharCount>k){
                 arr[s[i]-'a']--; 
                 if(arr[s[i]-'a']==0){
                 uniqueCharCount--;
               }
                i++;
             }
             j++;
         }
         return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends