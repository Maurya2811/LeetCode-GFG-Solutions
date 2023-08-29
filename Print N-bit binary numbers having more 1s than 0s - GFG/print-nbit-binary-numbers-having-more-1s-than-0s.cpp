//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

   vector<string> ans;
   
   int n;
   
   void solve(int one,int zero,string temp){
       if(one+zero == n){
           ans.push_back(temp);
           return;
       }
       
       solve(one+1,zero,temp+'1');
       
       if(zero<one){
           solve(one,zero+1,temp+'0');
       }
       return;
   }
	vector<string> NBitBinary(int N)
	{
	   
	   n=N;
	   solve(0,0,"");
	   
	   return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends