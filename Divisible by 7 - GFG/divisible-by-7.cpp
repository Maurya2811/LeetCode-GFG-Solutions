//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int isdivisible7(string num){
        // Divisibility of 7 is
        // start from last Take sum of  (3-3 pair) alternately in two temps 
        // if the diff bet both the sum is 0 or multiple of 7 then it is divisible bt 7
        
        int n=num.length();
        
        bool turn=false;
        
        long long sum1=0;
        long long sum2=0;
            for(int i=n-1;i>=0;i--){
                  
                if(turn){
                     int len =3;
                    if(i<2){
                        len=i+1;
                        i=2;
                    }
                       
                    string temp= num.substr(i-2,len);
                    sum1+=stoi(temp);
                 
                }else{
                    int len =3;
                    if(i<2){
                        len=i+1;
                        i=2;
                    }
                    string temp= num.substr(i-2,len);
                    sum2+=stoi(temp);
                }
                turn=!turn;
                i-=2;
            }
            // cout<<sum1<<sum2<<" ";
            return ((sum2-sum1)%7)==0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}
// } Driver Code Ends