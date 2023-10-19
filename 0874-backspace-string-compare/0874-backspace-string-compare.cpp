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