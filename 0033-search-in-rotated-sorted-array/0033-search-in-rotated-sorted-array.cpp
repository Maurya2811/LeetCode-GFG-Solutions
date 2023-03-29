class Solution {
public:
    int search(vector<int>& nums, int target) {
       int low =0,high=nums.size()-1;
        int mid;
        while(low<=high){
            mid= (low + high)>>1;
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid]>=nums[0]) // left side is sorted
            {
                // figure out if element lies on left side or not
                if(target >=nums[low] && target <=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
             /* Right side is sorted */
            else{
                 if(target >=nums[mid] && target <=nums[high])
                     low=mid+1;
                 else{
                     high =mid-1;
                 }
             }
        }
        return -1;
    }
};