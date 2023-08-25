class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nums;
           int n1 = nums1.size(), n2 = nums2.size();
           int size = n1+n2;
          int pre,curr;
        int i=0,j=0;
        while(i< n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                nums.push_back(nums1[i++]);
                 
            }else{
                nums.push_back(nums2[j++]);
            }
            if(nums.size() == size/2  ){
               
                pre = nums.back();
            }
            
            if(nums.size() == ((size/2)+1)){ 
             
                 curr = nums.back();
            }
        }
        while(i<n1){
             nums.push_back(nums1[i++]);
             if(nums.size() == size/2  ){
                pre = nums.back();
            }
            
            if(nums.size() == ((size/2)+1)){ 
                 curr = nums.back();
            }
        }
          while(j<n2){
             nums.push_back(nums2[j++]);
               if(nums.size() == size/2  ){
                pre = nums.back();
            }
            if(nums.size() == ((size/2)+1)){ 
                 curr = nums.back();
            }
        }
        // cout<< " prev"<<pre <<endl;
        // cout<< "curr "<<curr<< endl;
        if((size&1) == 0){
            return (double) (pre+curr)/2.0;
        }
        return (double)curr;
    }
};