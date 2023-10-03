class Solution {
public:

   int getSum (int num){
       return (num*(num+1))/2;
   }
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101]={0};
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
    int ans=0;
        for(int i=0;i<=100;i++){
            if(freq[i]>0){
                ans+=getSum(freq[i]-1);
            }
        }
        return ans;
    }
};