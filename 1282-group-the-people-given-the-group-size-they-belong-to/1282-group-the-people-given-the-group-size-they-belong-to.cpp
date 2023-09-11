class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
         vector<vector<int>>ans;
        
        int n=groupSizes.size();
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
            
            if(mp[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }
        }
        
//         for(auto &x:mp){
//             int i = x.first;
//             vector<int> temp = x.second;
//             int size = temp.size()/2;
            
//             for(int j=0;j<size;j++){
//                   vector<int>temp1;
//                 for(int z=0;z<i;z++){
//                     temp1.push_back(temp.back());
//                     temp.pop_back();
//                 }
//                 ans.push_back(temp1);
//             }
            
//         }
        return ans;
    }
};