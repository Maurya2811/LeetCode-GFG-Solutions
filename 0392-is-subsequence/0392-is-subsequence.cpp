class Solution {
public:
    int m,n;
    
    bool solve(int i, int j, string &s, string &t){
        if(i>=m)
            return true;
        if(j>=n)
            return false;
        
        bool ans1 = false;
        bool ans2 = false;
        if(s[i]==t[j]){
            ans1 = solve(i+1,j+1,s,t);
            if(ans1)
                return true;
        }
          
        else{
          ans2 = solve(i,j+1,s,t);
        }
        
        return ans1 | ans2 ;
    }
    
    bool isSubsequence(string s, string t) {
        m=s.length();
        n=t.length();
        
        return solve(0,0,s,t);
    }
};