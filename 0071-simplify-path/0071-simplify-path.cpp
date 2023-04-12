// 2 approaches
//              1. Using Stack
//             2. Using String
   
class Solution {
public:
    
    string simplifyPath(string path) {
   // /*
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
        // */
        
  //             2. Using Vector
/*
        stringstream ss(path);
        string token="";
        vector <string>st;
        while(getline(ss,token,'/')){
            if(token == "." || token == "")
                continue;
            if(token!=".." )
               {  
                st.push_back(token);
               }
            else if (!st.empty())
                st.pop_back();         
            
        }
        
        if(st.empty())
            return "/";
        
        string ans="";
     
        for(auto &it:st){
           ans =ans + "/" + it;
       }
        
        return ans;
        
 */
    }
};