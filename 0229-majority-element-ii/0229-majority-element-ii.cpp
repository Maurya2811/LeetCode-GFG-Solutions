class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1=0;
        int maj1=NULL;
        int count2=0;
        int maj2=NULL;

        int n = nums.size();

        for(int i=0;i<n;i++){

              if(nums[i]==maj1){
                  count1++;
              }
             else if(nums[i]==maj2){
                  count2++;
              }
             else if(count1==0){
                maj1=nums[i];
                count1=1;
             }
             else if(count2==0){
                maj2=nums[i];
                count2=1;
             }
             else{
                 count1--;
                 count2--;
             }
        }

          int freq1=0,freq2=0;
        for(int &x:nums){ 
            if(x==maj1){
                freq1++;
            }
           else if(x==maj2){
                freq2++;
            }
        }

 vector<int> ans;
        if(freq1>(n/3)){
              ans.push_back(maj1);
        }
        if(freq2>(n/3)){
              ans.push_back(maj2);
        }
     
     return ans;
    }
};