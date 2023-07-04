class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0 ;
         for(int bit =0;bit<32 ;bit++ ){
             int temp = 1<<bit;
             int countZeros=0,countOnes=0;
             for(int &x:nums){
                 if(x & temp){
                     countOnes++;
                 }
                 else
                     countZeros++;
             }
             if(countOnes%3==1){
                 ans = ans | temp;
             }
         }
        return ans;
    }
};