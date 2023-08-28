//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
  int n;
  vector<string> ans;
    
    void solve(int idx, string temp,string &s){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        
        solve(idx+1,temp+" "+s[idx],s);
        solve(idx+1,temp+s[idx],s);
        return;
    }
    vector<string> permutation(string s){
         n= s.length();
         
         string temp;
         temp.push_back(s[0]);
         solve(1,temp,s);
    return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends