//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string &str)
    {
            int len = str.length();
 
    int num, rem = 0;
 
    // loop that find remainder
    for (int i = 0; i < len; i++) {
        num = rem * 10 + (str[i] - '0');
        rem = num % 11;
    }
 
    return rem;   
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends