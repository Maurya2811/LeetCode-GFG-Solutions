class Solution {
public:
    //Approach-1 (Using Concept of LCS)
    int LCS(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(m+1));
        
        for(int row = 0; row<m+1; row++) {
            t[row][0] = 0;
        }
        
        for(int col = 0; col<n+1; col++) {
            t[0][col] = 0;
        }
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        return t[m][n];
    }
      int longestPalindromeSubseq(string s) {
        string s1 = s;
        
        reverse(s1.begin(), s1.end());
        int m = s.length();
        
        return LCS(s, s1, m, m); //Approach-1
        
      
    }
};
    

    