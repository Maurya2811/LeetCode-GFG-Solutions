class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
        return nums;

        if(n==2){
            if(nums[0]==nums[1]){
                return {nums[0]};
            }
            return nums;
        }

        set<int> st;
        int size = n/3;
         vector<int> ans;
         for(int i=0;i<n-1;i++){
             int freq =1;
             int ele = nums[i];
             for(int j=i+1;j<n;j++){
                 if(nums[j]==ele){
                     freq++;          
                     }
                 if(freq>size){    
                          st.insert(nums[i]);
                          break;
                      }
                 }
             }
          

         return vector<int>(st.begin(),st.end());
         }
};