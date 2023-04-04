class Solution {
public:
     vector<vector<int>> permutations(vector<int>&nums ,int i, vector<vector<int>> &vec){
        
        if(i>=nums.size()){
             vec.push_back(nums);
            return vec;
        }
           
         
         for(int j=i;j<nums.size();j++){
             swap(nums[i],nums[j]);
             permutations(nums , i+1,vec);
              swap(nums[i],nums[j]);
         }
        return vec;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> vec;
       permutations(nums,0,vec);
        return vec;
    }
};