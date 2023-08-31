class Solution {
public:

   void solve(int i,vector<int> &temp,vector<int>& candidates, int target,vector<vector<int>>&ans,int &n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
         if(i>=n || target<0 ){
              return;
         }
       
       if(candidates[i]<=target){
           
           // vector<int> temp1 = temp;
           temp.push_back(candidates[i]);
           solve(i,temp,candidates,target-candidates[i],ans,n) ;
           temp.pop_back();
           
       }
           solve(i+1,temp,candidates,target,ans,n) ;
       
       return;
    }
    
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
                int n= candidates.size();
                vector<int> temp;
                solve(0,temp,candidates,target,ans,n);
                 return ans;
    }
};