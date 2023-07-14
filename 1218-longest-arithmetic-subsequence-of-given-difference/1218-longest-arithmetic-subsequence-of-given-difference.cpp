class Solution {
public:
 
    int longestSubsequence(vector<int>& arr, int &diff) {
        unordered_map<int,int>mp;
       int n = arr.size();
         int result =0;
        for(int i=0;i<n;i++){
            int prev = arr[i]-diff;
            int length_till_prev = mp[prev];
            mp[arr[i]]= length_till_prev+1;
            
            result = max(result,mp[arr[i]]);
        }
        return result;
    }
};