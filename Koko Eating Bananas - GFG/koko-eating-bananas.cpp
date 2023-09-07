//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
     bool canEat(int bananas, vector<int>& piles, int H){
         int hour =0;
         for(int &x: piles){
             hour+=(x/bananas);
             if(x%bananas){
                 hour++;
             }
             if(hour>H)
             return false;
         }
         return true;
     }
    int Solve(int N, vector<int>& piles, int H) {
       
       int maxi = 0;
       for(int &x:piles){
           if(x>maxi){
               maxi = x;
           }
       }
       
       int start = 1, end = maxi;
       
       while(start<end){
           
           int mid = start + (end-start)/2;
           
           if(canEat(mid,piles,H)){
               end = mid;
               
           }else{
               start = mid+1;
           }
       }
       return end;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends