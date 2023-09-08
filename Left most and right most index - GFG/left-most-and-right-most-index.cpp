//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int n;
   long long findLeftIndex(vector<long long> &v, long long x){
       
       long long start =0, end = n-1;
       long long res=-1;
       while(start<=end){
           long long mid= start + (end-start)/2;
           
           if(v[mid]==x){
               res = mid;
               end = mid-1;
           }else if(v[mid]<x){
               start = mid+1;
           }else{
               end= mid-1;
           }
       }
       return res;
   }
   
    long long findRightIndex(vector<long long> &v, long long x){
       
       long long start =0, end = n-1;
       long long res=-1;
       
       while(start<=end){
           
           long long mid = start + (end-start)/2;
           
           if(v[mid]==x){
               res = mid;
               start = mid+1;
           }else if(v[mid]<x){
               start = mid+1;
           }else{
               end= mid-1;
           }
       }
       return res;
   }
    
    pair<long,long> indexes(vector<long long> &v, long long x)
    {
        long long left =-1,right =-1;
        n = v.size();
        left = findLeftIndex(v,x);
        right = findRightIndex(v,x);
        
        return {left,right};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends