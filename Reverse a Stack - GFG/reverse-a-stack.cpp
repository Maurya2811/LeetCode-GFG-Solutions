//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

void reverse(stack<int> &st,int &target,int i){
    if(st.size()==i){
        st.push(target);
        return;
    }
    int temp=st.top();
    st.pop();
     reverse(st,target,i);
     st.push(temp);
}

   void solve(stack<int> &st,int &size){
       int i=0;
       while(i<size){
           int target=st.top();
            st.pop();
           reverse(st,target,i);
           i++;
       }
       
   }
    void Reverse(stack<int> &st){
        int size=st.size();
        
        solve(st,size);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends