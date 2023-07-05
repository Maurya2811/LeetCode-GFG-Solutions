// Brute Force

class Solution {
public:
    int n;
    
      int findMaxSubArr(vector<int>& nums,int skip_idx){
          int currLen =0, maxLen =0;
           
          for(int i=0;i<n;i++){
              if(i==skip_idx){
                  continue;
              }
              else if(nums[i]==1){
                  currLen++;
                  maxLen = max(currLen,maxLen);
                  
              }
              else{
                  currLen =0;
              }
              
          }
          return maxLen;
          
      }
          
          
    int longestSubarray(vector<int>& nums) {
        n= nums.size();
        int result =0, zeroCount =0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount++;
             result = max(result, findMaxSubArr(nums,i));
            }
        }
        
        
       return zeroCount==0 ? n-1 : result;
    }
};

// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
        
//     }
// };