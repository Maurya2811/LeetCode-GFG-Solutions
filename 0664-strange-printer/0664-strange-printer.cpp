class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(string &s, int l, int r){
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        
        
        if(t[l][r]!=-1)
            return t[l][r];
        
        int i=l+1;
        
        while(i<=r && s[i]==s[l]){
            i++;
        }
        if(i==r+1)
            return 1;
        
        int basic_ans = 1 + solve(s,i,r);
        
        int lalach = INT_MAX;
         for(int j=i ; j<=r;j++){
             if(s[j]==s[l]){
             int ans = solve(s,i,j-1)+solve(s,j,r);
             
             lalach = min(lalach,ans);
             }
         }
        
        return t[l][r]=min(lalach,basic_ans);
    }
    
    int strangePrinter(string s) {
        
        n = s.length();
         t.resize(n+1,vector<int>(n+1,-1));
           return solve(s,0,n-1);
    }
};