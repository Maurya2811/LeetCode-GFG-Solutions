class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n=s.length();
        if(k==1 && k>=n)
        return s;
        
        for(int i=0;i<n;i++){
            
            int j= i+k; 
            if(j<=n)
            reverse(s.begin()+i,s.begin()+j);
            else
            reverse(s.begin()+i,s.end());
            
            i=j+k-1;

        }
       
        
        return s;
    }
};