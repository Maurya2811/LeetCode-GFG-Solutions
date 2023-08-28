class Solution {
public:
// tolower(ch) OR toupper(ascii)
// they return ASCII value which mush be type-casted to char
    
    vector<string> ans;
    int n;
    
    void solve(int idx, string &s, string temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        
        if(s[idx]>='0' && s[idx]<='9'){
            solve(idx+1, s, temp+s[idx]);
            return;
        }
       string temp1 = temp;
        temp1.push_back(toupper(s[idx]));
        
        solve(idx+1, s,temp1 );
        
        string temp2 = temp;
        temp2.push_back(tolower(s[idx]));
                   
        solve(idx+1, s, temp2);

    return;
    }
    
    vector<string> letterCasePermutation(string s) {
           n = s.length();
        
       
        solve(0,s,"");
        
        return ans;   
    }
};