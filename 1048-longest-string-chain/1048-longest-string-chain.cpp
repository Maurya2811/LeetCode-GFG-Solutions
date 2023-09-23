class Solution {
public:
    int n;
      int dp[1001][1001];
    
   static bool lambda(string num1 ,string num2){
            return num1.length()<num2.length();
        }
    
    bool isPredecessor(string &s1 , string &s2){
        
        int n=s1.length();
        int m=s2.length();
        
          if(m-n!=1)
              return false;
        
          int j=0;
        for(int i=0;i<m;i++ ){
            if(s1[j]==s2[i]){
                j++;
            }
        }
        return j==m-1;  // Since the difference  between length of two words is 1;
    }
    
    int solve(vector<string>& words,int prev,int curr){
        
        
        if(curr>= n)
            return 0;
        
        if( prev!=-1 && dp[prev][curr]!=-1)
            return dp[prev][curr];
        
        int taken =0 ;
          if(prev ==-1 || isPredecessor(words[prev],words[curr]))
              taken = 1 + solve(words,curr,curr+1);
      
            
            int not_taken = solve(words,prev,curr+1);
        
              if( prev!=-1){
                  dp[prev][curr] = max(taken,not_taken);
              }
        
        return max(taken,not_taken);
    }
    
    int longestStrChain(vector<string>& words) {
        
        n=words.size();
        if(n==1)
            return 1;
        
        sort(words.begin(),words.end(),lambda);
        
      
        memset(dp,-1,sizeof(dp));
        
      return  solve(words,-1,0);
       
        
    }
    
};