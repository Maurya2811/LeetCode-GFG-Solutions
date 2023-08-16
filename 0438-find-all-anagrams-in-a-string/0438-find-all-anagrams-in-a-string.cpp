class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int k = p.length();
        
        int n = s.length();
        
        unordered_map<char,int> mp;
        
        for(char &c: p){
            mp[c]++;
        }
        int count = mp.size();
        
        int i=0,j=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if(j-i+1==k){
                if(count==0){
                    ans.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1){
                    count++;
                }
              }
                i++;
            }
            j++;
        }      
            
            return ans;
    }
};