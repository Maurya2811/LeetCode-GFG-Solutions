//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    long long int count=0;
    void merge(long long arr[],long long int start,long long int mid,long long int end,vector<long long>&temp){
        long long int i=start;
        long long int j=mid+1;
        long long int k=start;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
            
            else {
            temp[k++]=arr[j++];
                count+=mid-i+1;
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
           temp[k++]=arr[j++];
        }
        while(start<=end){
            arr[start]=temp[start];
            start++;
        }
        
    }
 
    void mergesort(long long arr[],long long int start,long long int end,vector<long long>&temp){
        if(start>=end)
        return;
        
       long long int mid= start +(end-start)/2;
        
        mergesort(arr,start,mid,temp);
        mergesort(arr,mid+1,end,temp);
        merge(arr,start,mid,end,temp);
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        vector<long long>temp(N);
        mergesort(arr,0,N-1,temp);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends