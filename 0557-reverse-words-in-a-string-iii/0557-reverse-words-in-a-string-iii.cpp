class Solution {
public:
    string reverseWords(string s) {
            string temp=" ";
            string ans="";
        int n = s.length();
            for(int i=0;i<n;i++){
                if(s[i]==' '){
                    ans+=temp;
                    temp=" ";
                    i++;
                }
                temp=s[i]+temp;
            }
        ans+=temp;
        ans.pop_back();
        
        return ans;
    }
};