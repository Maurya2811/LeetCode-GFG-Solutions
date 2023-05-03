class Solution {
public:
    vector<int> solve(vector<int>& nums1,vector<int>& nums2){
        unordered_set<int> ans1;
        for(auto &x: nums1){
            bool flag=false;
              for(auto &y:nums2){
                  if(x==y){
                      flag=true;
                  }
              }
            if(!flag)
                ans1.insert(x);
        }
           return vector<int>(ans1.begin(),ans1.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        return {solve(nums1, nums2),solve(nums2, nums1)};
    }
};