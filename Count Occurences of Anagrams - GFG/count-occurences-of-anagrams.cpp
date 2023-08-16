//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int size = txt.length();
	    int k = pat.length();
	      int count=0;
	    
	    vector<int> freq(26,0);
	    for(int i=0;i<k;i++){
	        if(freq[pat[i]-'a']==0){
	            count++;
	        }
	        freq[pat[i]-'a']++;
	    }
	    
	    int i=0,j=0;
	    int ans=0;
	    while(j<size){
	        freq[txt[j]-'a']--;
	        if(freq[txt[j]-'a']==0)
	           count--;
	           
	           if(j-i+1==k){
	               if(count==0){
	                   ans++;
	               }
	          
	             if(freq[txt[i]-'a']==0)
	                 count++;
	             freq[txt[i]-'a']++;
	             i++;
	           }
	           j++;
	    }
	   return ans; 
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends