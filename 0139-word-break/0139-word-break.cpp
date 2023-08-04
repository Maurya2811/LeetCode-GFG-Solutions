class Solution {
public:
     
    int n;
    unordered_set<string> st;
    int dp[301];
    bool solve(string &s,int idx){
        if(idx>=n){
            return true;
        }
          if(dp[idx]!=-1)
              return dp[idx];
        
        if(st.find(s.substr(idx))!=st.end())
            return dp[idx]=true;
        
        for(int i=1;i<=n;i++){
            
            string temp = s.substr(idx,i);
            if(st.find(temp)!=st.end() && solve(s,idx+i)){
                return dp[idx]= true;
            }       
        }
        
        return dp[idx]= false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
       
        for(string word: wordDict){
            st.insert(word);
        }
        if(st.find(s)!=st.end()){
            return true;
        }
      memset(dp,-1,sizeof(dp));
        
        
        return solve(s,0);
        
    }
};