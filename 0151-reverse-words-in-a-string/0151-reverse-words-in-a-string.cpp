class Solution {
public:
    string reverseWords(string s) {
        
        
          while(s[0]==' '){
            s.erase(s.begin());
        }
        int j=s.length()-1;
        
        string word="";
        string ans="";
        for( j ;j>=0;j--){
            if(s[j]==' '){
                while(j>0 && s[j]==' '){
                    j--;
                }
                j++;
                ans += word + " ";
                word="";
            }
            else{
                word = s[j]+ word;
            }
        }
        
        ans = ans+word;
        
        while(ans[0]==' '){
            ans.erase(ans.begin());
        }
         while(ans[ans.length()-1]==' '){
            ans.erase(ans.begin()+ans.length()-1);
        }
        return ans;
    }
};