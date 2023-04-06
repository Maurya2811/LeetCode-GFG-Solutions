class Solution {
public:
    
    bool isValid(vector<int>& nums,int mid,int &n){
        vector< long long > arr (nums.begin(),nums.end());
     
        for(int i=0;i<n-1;i++){
            if(arr[i]>mid)
                return false;
           long long buffer=mid-arr[i];
            arr[i+1]=arr[i+1]-buffer;  
        }
        // if(arr[n-1]>mid)
        //     return false; 
        // return true;
        return arr[n-1]<=mid;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int size=nums.size();
        int maxLeft=nums[0]; // since Number at 1st position cant be minimized
        int maxRight = *max_element(nums.begin(),nums.end());
        
        int result =0;
        while(maxLeft<=maxRight){
            int mid = maxLeft + (maxRight-maxLeft)/2;
            if(isValid(nums,mid,size)){
                result = mid;
                maxRight=mid-1;
            }
            else{
                maxLeft=mid+1;
            }
        }
        return result;
    }
};