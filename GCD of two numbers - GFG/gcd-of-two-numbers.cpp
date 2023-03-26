//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int a, int b) 
	{ 
	    // Usong Recursion
	   // if(A==0 || B==0)
	   // return A==0 ? B : A;
	    
	   // if(A>B)
	   // gcd(A-B,B);
	   // else
	   //  gcd(B-A,A);
	   if(a==0)
	   return b;
	   if(b==0)
	   return a;
	   while(a>0 && b>0){
	      if(a>b)
	        a=a-b ;
	      else
	        b=b-a;
	   }
	    if(a==0 || b==0)
	    return a==0 ? b : a;
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends