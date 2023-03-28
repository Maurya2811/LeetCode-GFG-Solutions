class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Using Hash Map  
        unordered_map<int ,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]]>0)
                return true;
           hash[nums[i]]++;
       }
        return false;
    }
};