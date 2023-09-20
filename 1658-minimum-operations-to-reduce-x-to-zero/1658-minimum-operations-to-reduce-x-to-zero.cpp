// Recursion (TLE)
/*
class Solution {
public:
     
    int ans=INT_MAX;
    
    void solve(int leftIdx,vector<int>&nums, int rightIdx,int sum,int count){
        
        if(sum==0 ){
            ans = min(ans,count);
            return ;
        }
            
        if(leftIdx>rightIdx)
            return; 
        
            solve(leftIdx+1,nums,rightIdx,sum-nums[leftIdx],count+1);
        
            solve(leftIdx,nums,rightIdx-1,sum-nums[rightIdx],count+1);
        
    }
    int minOperations(vector<int>& nums, int x) {
        
          int n=nums.size();
         solve(0,nums,n-1,x,0);
    return ans==INT_MAX ? -1: ans;
    }
};

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum<x)
            return-1;
        int n = nums.size();
        int i=0,j=0;
        int temp=0;
        int maxLen =0;
        int tar = sum-x;
        bool found=false;
        while(j<n){
            
              temp+=nums[j];
            
             while(temp>tar){
                temp-=nums[i];
                i++;
            }    
            if(temp==tar){
                found=true;
                maxLen = max(maxLen,(j-i+1));
            }
          
            j++;
        }
        return found ? n-maxLen:-1 ;
    }
};