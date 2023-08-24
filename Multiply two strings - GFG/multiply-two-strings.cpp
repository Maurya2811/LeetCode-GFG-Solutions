//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
   bool removeMinus(string &s){
       if(s[0]=='-'){
           s.erase(s.begin());
           return true;
       }
       return false;
   }
   
   bool removeLeadingZeros(string &s){
       while(s.length()>0 && s[0]=='0' ){
           s.erase(s.begin());
       }
   }
    string multiplyStrings(string s1, string s2) {
        
      bool isZeroinS1= removeMinus(s1);
      bool isZeroinS2= removeMinus(s2);
       
       removeLeadingZeros(s1);
       removeLeadingZeros(s2);
       int len1 = s1.length();
        int len2 = s2.length();
         int len =len1+len2+1;
       int res[len]={0};
    //   memset(res, 0, sizeof(res));
       int carry=0;
      
       for(int i=0; i<len2;i++){
             int n1 = s2[len2-1-i]-'0';
           
           for(int j=0; j<len1;j++){
                 int n2 = s1[len1-1-j]-'0';
                    res[len-1-i-j]+=  n1*n2 +carry;
                   carry = res[len-1-i-j]/10;
                   res[len-1-i-j]%=10;
            }
            if(carry){
                res[len-1-i-len1]=carry;
                carry=0;
            }
       }
     string ans="";
     int i=0;
     while(res[i]==0){
         i++;
     }
     while(i<len){
         ans +=res[i]+'0'; 
         i++;
     }
    if((isZeroinS1 && isZeroinS2) || (!isZeroinS1 && !isZeroinS2) ){
        return ans;
    }else{
       ans = '-'+ans;
    }
    return ans;
    }
};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends