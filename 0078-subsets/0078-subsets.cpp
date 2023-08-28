class Solution {
public:
     // Given that in All the elements are unique so the Power set will also 
    // consists of only unique elements..
    //We dont have to think about the duplicates set
    
    int n;
    vector<vector<int>> ans;
    
    void solve(int idx ,vector<int> temp, vector<int>& nums){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        
        solve(idx+1,temp,nums);
        
        temp.push_back(nums[idx]);
                
        solve(idx+1,temp,nums);
       return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
          n= nums.size();
        
        solve(0,{},nums);
        
        return ans;
    }
};