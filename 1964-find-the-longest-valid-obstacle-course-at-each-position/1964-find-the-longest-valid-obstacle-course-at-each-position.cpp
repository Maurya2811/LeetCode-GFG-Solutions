// Longest Increasing subsequences

// 1 Brute Force   O(n2)
/*
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n=nums.size();
        vector<int> LIS(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<=nums[i]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
        }
        return LIS; 
    }
};
*/


// 2. Optimal
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n=nums.size();
        vector<int> LIS;
        vector<int> result(n);
        
        for(int i=0;i<n;i++){
            int idx = upper_bound(begin(LIS),end(LIS),nums[i]) - begin(LIS); 
            if(idx==LIS.size())
                LIS.push_back(nums[i]);
            else
                LIS[idx]=nums[i];
            
            result[i]=idx+1;
        }
        return result;
    }
};