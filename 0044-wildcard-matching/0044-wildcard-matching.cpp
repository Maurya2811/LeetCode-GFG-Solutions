class Solution {
public:
    
    bool solve(string &s,int i,string &p,int j, vector<vector<int>>&dp){
        // Base Case
      
        // 1. If both pointer goes OutOfBound then return True
        if(i==s.size() && j==p.size())
            return true;
        // If pattern contains many "*" at the end
        if(i==s.size() && j<p.size()){
           while(j < p.size()){
               if(p[j]!='*'){     
                   return false;    
              }
                j++;    
           }
              return true;
        }
          if(dp[i][j]!=-1)
            return dp[i][j];
        
        // String char Matching
        if(s[i]==p[j] || p[j]=='?')
             return dp[i][j]=solve(s,i+1,p,j+1,dp);
     
        
        
       
        if(p[j]=='*'){
   
        bool caseA  =   solve(s,i,p,j+1,dp)   ;
          //     "*" when it behaves as Empty String  
            
            
       bool caseB  =    solve(s,i+1,p,j,dp)  ;       
        //    "*" when it consumes one char at a time      

  return dp[i][j]= (caseA || caseB) ;
          
        }
         
          return false;
    }
    
    
    
    bool isMatch(string s, string p) {
        int i=0,j=0;
        vector<vector<int>>dp (s.size()+1,vector<int>(p.size()+1,-1));
      return  solve(s,i,p,j,dp);
        
    }
};