class Solution {
public:
    string removeStars(string s) {
       // 3 approaches 
         
        //  1. Using Stack
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                st.pop();
            }
            else 
                st.push(s[i]);
        }
        string str ="";
     while(!st.empty()){
         str+=st.top();
         st.pop();
     }
        reverse(str.begin(),str.end());
       return str;
    }
};