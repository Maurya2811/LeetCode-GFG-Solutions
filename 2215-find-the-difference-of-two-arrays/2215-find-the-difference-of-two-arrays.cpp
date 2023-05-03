class Solution {
public:
    // Brute Force
    /*
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
    */
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
       set<int> st1(nums1.begin(),nums1.end());
        
       set<int> st2(nums2.begin(),nums2.end());
        
        vector<int> v1;
        vector<int> v2;
        
        set_difference(st1.begin(),st1.end(),st2.begin(),st2.end(),back_inserter(v1));
         set_difference(st2.begin(),st2.end(),st1.begin(),st1.end(),back_inserter(v2));
        
        return {v1,v2};
    }
};