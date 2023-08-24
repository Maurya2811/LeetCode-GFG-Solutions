class Solution {
public:
    string makeString(string &s){
        string ans="";
        
        for(char &ch : s){
            if(ch>='a'&& ch<='z')
                ans+=ch;
            else if(ch>='A'&& ch<='Z'){
                ans+=(char)tolower(ch);
            }
            else if(ch>='0' && ch<='9'){
                ans+=ch;
            }
        }
        return ans;
    }
    bool isPalindrome(string s) {
       
       string str =  makeString(s);
    cout<<str;
        int i=0;
       int j=str.length()-1;
        if(j<1)
            return true;
        while(i<j){
            if(str[i++]!=str[j--])
                return false;
        }
        return true;
    }
};