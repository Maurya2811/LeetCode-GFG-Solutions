class Solution {
public:
    void sortColors(vector<int>& nums) {
      int i=0,len=nums.size();
     int start=0,end=len-1;
     while(i<=end)
     {
         if(nums[i]==0)
         {
             swap(nums[i++],nums[start++]);    
         }
         else if(nums[i]==2){
         swap(nums[i],nums[end]);
         end--;
         }
         else 
         i++;
     }
    }
};