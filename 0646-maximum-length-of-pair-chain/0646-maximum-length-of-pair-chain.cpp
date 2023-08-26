//Approach-1 (Using Simple LIS recursion+memo) - Since Qn asks to take pairs in any order, we sort it in the beginning
class Solution {
public:
   
    int n;
    int t[1001][1001];
    
    int lis(vector<vector<int>>& nums, int prev_idx, int curr_idx) {
       if(curr_idx == n)
           return 0;
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx][0] > nums[prev_idx][1])
            taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        n = pairs.size();
        sort(begin(pairs), end(pairs)); //You can select pairs in any order.
        return lis(pairs, -1, 0);
    }
};
