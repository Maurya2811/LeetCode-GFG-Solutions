//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        
        if(N==1 && S==0){
            return "0";
        }
        if(N>1 && S==0){
            return "-1";
        }
        string ans="";
        
        while(S>9 && N>0){
            ans+='9';
            S-=9;
            N--;
        }
        
        while(N){
            ans+= (S+ '0');
            S=0;
            N--;
        }
        if(S>0)
        return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends