// 2 approaches
//              1. Using Stack
     
   
class Solution {
public:
    
    string simplifyPath(string path) {
        stringstream ss(path);
        string token="";
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token == "." || token == "")
                continue;
            if(token==".." )
               { 
                if(!st.empty())
                st.pop();
               }
            else 
                st.push(token);
             //  if(token!="..")
             //       st.push(token);
             // else if(!st.empty())
             //      st.pop();
               
            
        }
        if(st.empty())
            return "/";
        string ans="";
        while(!st.empty()){
            ans = "/"+ st.top() + ans;
            st.pop();
        }
        return ans;
    }
};