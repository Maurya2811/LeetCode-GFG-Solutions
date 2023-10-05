class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj=NULL;
        int count=0;
       int n=nums.size();
        for(int i=0;i<n;i++){
              if(count==0){
                 maj=nums[i];
                 count=1;
             }else if(maj==nums[i])
                 count++;
             else{
                 count--;
             } 
        }
       return maj;
    }
};