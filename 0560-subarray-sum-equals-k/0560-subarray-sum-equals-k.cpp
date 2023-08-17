class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
      int i = 0, j = 0;
    int n = arr.size();
    long long sum = 0;
    int maxi = 0;
     unordered_map<long long , int> mp;
     while(j<n){
            sum += arr[j]; 
            if(sum == k){
                maxi++;
            }
            if(mp.find(sum-k)!=mp.end()){
               maxi+=mp[sum-k];
            }
                mp[sum]++;
            j++;
        }
       return maxi; 
    }
};