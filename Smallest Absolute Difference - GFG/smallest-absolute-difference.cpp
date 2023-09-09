//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


int kthDiff(int a[], int n, int K)
{
    int size ;
    if(n&1){
        size = n*(n-1)/2;
    }else{
        size = (n/2)*(n-1);
    }
    
    vector<int>ans(size,0);
    int z=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans[z++] = abs(a[i]-a[j]);
        }
    }
    
    sort(ans.begin(),ans.end());
    
    return ans[K-1];
    
}