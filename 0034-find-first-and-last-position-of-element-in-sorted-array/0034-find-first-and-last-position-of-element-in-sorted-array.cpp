class Solution {
public:
 int firstIndex(vector<int>& nums, int target){
     int s=0, e=nums.size()-1;
       int ans =-1;
       while(s<=e){
           int mid = s + (e-s)/2;

           if(nums[mid]==target){
               ans=mid;
               e=mid-1;
           }else if(nums[mid]>target){
               e=mid-1;
           }else{
               s=mid+1;
           }
       }
       return ans;
       
 }
 int lastIndex(vector<int>& nums, int target){
     int s=0, e=nums.size()-1;
       int ans =-1;
       while(s<=e){
           int mid = s + (e-s)/2;

           if(nums[mid]==target){
               ans=mid;
               s=mid+1;
           }else if(nums[mid]>target){
               e=mid-1;
           }else{
               s=mid+1;
           }
       }
       return ans;
       
 }
    vector<int> searchRange(vector<int>& nums, int target) {
           
           return {firstIndex(nums,target),lastIndex(nums,target)};
    }
};