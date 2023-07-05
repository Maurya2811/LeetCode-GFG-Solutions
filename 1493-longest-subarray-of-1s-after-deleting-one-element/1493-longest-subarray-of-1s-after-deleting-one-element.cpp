// Brute Force
/*
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
*/


// 2nd Sliding Window Appraoch
/*
class Solution {
public:
    int n=0;
    
    int longestSubarray(vector<int>& nums) {
        
        n= nums.size();
        int zeroCount=0,maxLen =0;
        int i=0,currLen=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                zeroCount++;
                while(zeroCount >1){
                   
                    if(nums[i]==0)
                        zeroCount--;
                     i++;
                }
               
            }
         currLen = j-i;
          maxLen = max(maxLen,currLen);
        }
        return maxLen;
        
    }
};
*/
// Best Appraoch
class Solution {
public:
     int n=0; 
    int longestSubarray(vector<int>& nums) {
        
        n= nums.size();
        int lastZeroIdx=-1,maxLen =0;
        int currLen=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               j= lastZeroIdx+1;
                lastZeroIdx=i;
            }
            currLen = i-j;
          maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};
// */