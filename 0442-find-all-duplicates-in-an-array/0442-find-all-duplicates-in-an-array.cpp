class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Marking the elements ( through absolute value at index) as visited if negative found
        // means element is already present in that array, push it and return after traversing
        
           vector<int> vec;
          for(int i=0;i<nums.size();i++){
              int val=abs(nums[i]);
             if(nums[val-1]<0){
                 vec.push_back(val);
             }
              else
                 nums[val-1] *= -1;
                   
          }
     return vec;
    }
};