class Solution {
public:
    vector<vector<int>> ans;
     
    void solve(int start, int &n, int k, vector<int> &temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solve(i+1,n,k-1,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,k,temp);
        return ans;
    }
};

/*
class Solution {
public:
    
    void solve(int i,vector<int>&temp,int k,int &n,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(i>n)
            return;
        
        temp.push_back(i);
        solve(i+1,temp,k-1,n,ans);
        temp.pop_back();
        solve(i+1,temp,k,n,ans);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>>ans;
          solve(1,temp,k,n,ans);
        
        return ans;
    }
};
*/