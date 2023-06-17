class Solution {
public:
    int n;
    map<pair<int,int>,int>mp;
    int solve(int i,vector<int>& arr1, vector<int>& arr2,int prev){
        if(i>=n)
            return 0;
        if(mp.find({i,prev}) != mp.end())
            return mp[{i,prev}];
        int result1 = 1e9 +1;
        
        if(arr1[i]>prev){
            result1 = solve(i+1,arr1,arr2,arr1[i]);
        }
        
      int result2 = 1e9 +1 ;
        auto it = upper_bound(arr2.begin(), arr2.end(),prev);
        if(it!= arr2.end()){
            int idx = it - arr2.begin();
            // arr1[i]=arr2[idx];
            result2 = 1 + solve(i+1,arr1,arr2,arr2[idx]);
        }
        
        return mp[{i,prev}]=min(result1,result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        sort(arr2.begin(), arr2.end());
        n = arr1.size();
        int result =solve(0,arr1,arr2,INT_MIN);
        return result == 1e9+1 ? -1 : result;
    }
};