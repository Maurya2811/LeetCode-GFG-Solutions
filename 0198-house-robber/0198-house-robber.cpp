class Solution {
public:
    int memory[101];
    int RobStartsIdx(vector<int>& nums,int i){
        if(i>=nums.size()){
              return 0;
        }
        if(memory[i]!=-1)
            return memory[i];
        
      int  maxProfit1 = nums[i] + RobStartsIdx(nums,i+2) ;
      int  maxProfit2 = 0 + RobStartsIdx(nums,i+1);
        return memory[i]=max(maxProfit1,maxProfit2);
    }
    int rob(vector<int>& nums) {
       memset(memory,-1,sizeof(memory));
       return RobStartsIdx(nums,0);
        
    }
};