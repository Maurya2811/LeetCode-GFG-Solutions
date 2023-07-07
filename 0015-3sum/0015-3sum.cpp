// Brute force TLE

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> tempSet;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i+1;j<n ;j++){
                int third = - (arr[i]+arr[j]);
                
                if(st.find(third)!=st.end()){
                    vector<int> temp ={arr[i],arr[j],third};
                    sort(temp.begin(),temp.end());
                    tempSet.insert(temp);
                }
                
              st.insert(arr[j]);
            }
        }
          vector<vector<int>> ans(tempSet.begin(),tempSet.end());
         
        return ans;
    }
};
*/

// Using Two Pointer

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1;
            int k =n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
            
        }
        
        return ans;
    }
};