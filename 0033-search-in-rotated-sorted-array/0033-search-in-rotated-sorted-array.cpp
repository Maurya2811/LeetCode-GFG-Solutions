class Solution {
public:
 int binarySearch(vector<int>&arr,int l,int r,int x)
 {
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
  
int findPivot(vector<int>& nums)
{
       int s=0,e=nums.size()-1;
        ios_base::sync_with_stdio(false);
          cin.tie(NULL); 
        int mid;
        // if(nums.size()>1 && nums[0]>nums[1])
        // return 0;
         if(s==e)
            return s;
        
        while(s<=e)
        {  
            mid=s+(e-s)/2;
            if(mid+1<nums.size() && nums[mid]>nums[mid+1]  )
            return mid;
            else if(mid-1 >0 && nums[mid-1]>nums[mid]  )
            return mid-1;
            else{
                if(nums[s]>nums[mid])
                 e=mid-1;
                  else
                 s=mid+1;
            }
        
        }
        return mid;
}
    int search(vector<int>& nums, int target) {
        int size=nums.size()-1;
          int index = findPivot(nums);
        cout<<index<<endl;
          int pivot = nums[findPivot(nums)];
         
          if(target> pivot)
          return -1;
          
          if(target>=nums[0])
         index=binarySearch(nums,0,index,target);
          else
          index = binarySearch(nums,index+1,size,target);

       return index == -1 ? -1: index;
    }
};