class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        st.push(-1);
        int maxCount=0,len=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i); // Yahi se gadbad hai
                }
                else{
                   
                    len=i-st.top();
                    maxCount= max(maxCount,len);
                }
            }
        }
        
        return maxCount;
    }
};