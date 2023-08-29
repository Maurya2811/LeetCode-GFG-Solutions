//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    vector<string> ans;
    
    void solve(int open,int close,string temp){
        if(open==0 && close ==0 ){
            ans.push_back(temp);
            return;
        }
        
        if(open>0){
             string op = temp ;
             op.push_back('(');
             solve(open-1,close,op);
             }
        if(close>open || open ==0){
             string op = temp ;
             op.push_back(')');
             solve(open,close-1,op);
        }
        
             
             return;
    }
    
    vector<string> AllParenthesis(int n) 
    {
         solve(n,n,"");
         
         return ans;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends