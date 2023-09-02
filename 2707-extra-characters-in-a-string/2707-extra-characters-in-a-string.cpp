class Solution {
public:
    unordered_set<string> st;
    int n;
    int dp[51];
    int solve(string &s, int idx) {
        if (idx >= n) 
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        string currStr = "";
        int minExtra = n;
        
        for (int i = idx; i < s.size(); i++) {
            
            currStr.push_back(s[i]);

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextExtra = solve(s, i + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        
        return dp[idx]=minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        for(string &word : dictionary) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};