class Solution {
public:
    
    vector<vector<int>>ans;
    int n;
     
   void solve(int i,vector<int> temp,vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
         if(i>=n){
             
             return;
         }
       
       if(candidates[i]<=target){
           
           vector<int> temp1 = temp;
           temp1.push_back(candidates[i]);
           solve(i,temp1,candidates,target-candidates[i]) ;
           
       }
           solve(i+1,temp,candidates,target) ;
       
       return;
    }
    
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
            n= candidates.size();
           solve(0,{},candidates,target);
        return ans;
    }
};