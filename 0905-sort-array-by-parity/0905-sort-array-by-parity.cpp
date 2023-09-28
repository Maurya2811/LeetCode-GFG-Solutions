class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       
        int n = nums.size();
        
        int i=0,j=n-1;
        
        while(i<j){
            
            while(j>=0 && (nums[j]&1)){
                j--;
            }
      
            while(i<n && !(nums[i]&1) ){
                i++;
            }
            if(i<n && j>=0 && i<j)
            swap(nums[i++],nums[j--]);
        }
        return nums;
    }
};