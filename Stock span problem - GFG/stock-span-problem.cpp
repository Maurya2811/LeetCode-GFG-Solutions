//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
        vector<int>ans(n);
        stack<pair<int,int>> st;   // (index,value)
        for(int i=0;i<n;i++){
            if(st.empty())
                 ans[i]=i+1;
           else if(arr[i]<st.top().second){
               ans[i]= i- st.top().first;
           }
           else{
               while(!st.empty() && st.top().second<=arr[i]){
                   st.pop();
               }
               if(st.empty()){
                   ans[i]=i+1;
               }else{
                   ans[i]=i - st.top().first;
               }
           }
           st.push({i,arr[i]});
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends