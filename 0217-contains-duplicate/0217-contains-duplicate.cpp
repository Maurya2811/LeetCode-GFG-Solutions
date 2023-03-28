class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Using Hash Map or WE can use Set contain to store elements ans check size
        
       //  unordered_map<int ,int> hash;
       //  for(int i=0;i<nums.size();i++){
       //      if(hash[nums[i]]>0)
       //          return true;
       //     hash[nums[i]]++;
       // }
       //  return false;
        
        // Using Sorting
         sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1])
               return true;
       }
        return false;
        
    }
};