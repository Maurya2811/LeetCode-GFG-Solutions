//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int n;
	int arr[1001][1001];
	  int solve(int i, int j, string &str){
	      if(i>= n || j>=n)return 0;
	      if(arr[i][j]!=-1)
	      return arr[i][j];
	      
	      if(str[i]==str[j] && i!=j)
	      return arr[i][j]= 1+ solve(i+1,j+1,str);
	      
	    return arr[i][j]=max(solve(i,j+1,str),solve(i+1,j,str)); 
	    
	  }
		int LongestRepeatingSubsequence(string str){
		    memset(arr,-1,sizeof(arr));
		    n= str.length();
		    return solve(0,0,str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends