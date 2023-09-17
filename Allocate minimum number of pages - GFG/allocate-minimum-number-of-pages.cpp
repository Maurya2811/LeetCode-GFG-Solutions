//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isValid(int &maxPages, int A[],int &N,int &M){
        int students =1;
        int sum = 0;
        
        for(int i=0;i<N;i++){
            
            sum += A[i];
            
            if(sum>maxPages){
                sum= A[i];
                students++;
            }
            if(students>M){
                return false;
            }
            
        }
        return true;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
      if(N<M)
        return -1;
        
        long long totalPages = 0, maxPageBook =0;
        
        for(int i=0;i<N;i++){
            totalPages+= A[i];
            if(A[i]>maxPageBook){
                maxPageBook = A[i];
            }
        }
        
        if(M==1){
            return totalPages;
        }
        
        
        int start = maxPageBook;
        long long end = totalPages - A[0]  ;
        int ans =-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(isValid(mid,A,N,M)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends