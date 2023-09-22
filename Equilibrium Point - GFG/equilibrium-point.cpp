//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
    
        if(n==1)
        return a[0];
    
        long long leftSum = 0;
        long long rightSum = 0;
        int i=0,j=n-1;
        
        
        
        while(i<j){
            if(leftSum<rightSum){
                leftSum+=a[i++];
            }else if(leftSum > rightSum){
                rightSum+=a[j--];
            }
            else{
                 leftSum+=a[i++];
                 rightSum+=a[j--];
            }
            if(leftSum == rightSum && i==j)
            return i+1;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends