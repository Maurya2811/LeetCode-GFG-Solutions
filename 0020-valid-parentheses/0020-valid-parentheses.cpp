// 2 Approaches 
class Solution {
public:
    bool isValid(string s) {
        // Approach 1 Using Stack
          stack<char> st;
        for(auto &ch: s){
            if(st.empty() || ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else if(ch==')' && st.top()!='(')
                return false;
            else if(ch=='}' && st.top()!='{')
                return false;
            else if(ch==']' && st.top()!='[')
                return false;
            else 
                 st.pop();
                
        }
        return st.empty();
    }
};