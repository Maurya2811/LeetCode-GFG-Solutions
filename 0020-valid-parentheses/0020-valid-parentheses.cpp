// 2 Approaches 
 // /*    
// Approach 1 Using Stack
class Solution {
public:  
   bool isValid(string s) {
          stack<char> st;
        for(auto &ch: s){
            if(st.empty() || ch=='(' || ch=='{' || ch=='['){
                // We are checking st.empty() because 1st bracket may me closed bracket
                // we if we are checking for only Open brackets and pushing it
                // if close bracket is not pushed then st.pop will make stack empty
                // and the program will return it True which gives wrong ans;
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
// */

    // 2 Approach
class Solution {
public: 
   bool isValid(string s) {
     
        stack<char> st;
          for(auto &ch: s){
              if(ch=='(')
                  st.push(')');
              else if(ch=='{')
                  st.push('}');
              else if(ch=='[')
                  st.push(']');
              else if(st.empty() || ch!=st.top())
                 return false;
              else
                  st.pop();
              
          }
         return st.empty();
      
    }
};
// */
    
 
