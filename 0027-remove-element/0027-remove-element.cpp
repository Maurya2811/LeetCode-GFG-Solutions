class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int i=0, j = nums.size()-1;
        
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j--]);
            }else{
                i++; 
                count++;
            }
        }
        return count;
    }
};