class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int skip_s=0;
        int skip_t=0;
        int i=s.length()-1;
        int j=t.length()-1;
       while(i >= 0 || j >= 0) {
            
            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }
            
            while(j >= 0) {
                if(t[j] == '#') {
                    skip_t++;
                    j--;
                } else if(skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }
            
            char first  = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];
            
            if(first != second)
                return false;
            
            i--;
            j--;
        }
        
        return true;
    }
};

// Brute Force
/*
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<int>s1;
        for(char &ch:s){
            if(ch=='#'){
                if(s1.size()){
                    s1.pop();
                }
            }
            else{
                s1.push(ch);
            }
        }
        stack<int>s2;
        for(char &ch:t){
            if(ch=='#'){
                if(s2.size()){
                    s2.pop();
                }
            }
            else{
                s2.push(ch);
            }
        }

        while(s1.size() && s2.size()){
            if(s1.top()!=s2.top()){
                return false;
            }else{
                s1.pop();
                s2.pop();
            }
        }
        if(s1.size() || s2.size())
        return false;

        return true;

    }
};
*/