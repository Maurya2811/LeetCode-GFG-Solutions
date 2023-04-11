class Solution {
public:
    string removeStars(string s) {
       // 3 approaches 
        
        
        // 1 Approach 
        // Using String
    // /* 
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
               str.pop_back();
            }
            else 
                str.push_back(s[i]);
         }
        return str;
   //  */
           
        //  2. Using Stack (Slow Approach)
        
       /* 
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                st.pop();
            }
            else 
                st.push(s[i]);
        }
        string result ="";
     while(!st.empty()){
         result.push_back(st.top());
         st.pop();
     }
        reverse(result.begin(),result.end());
       return result;
       */
        
    // Using 2 pointer 
        /*
        int size=s.length();
        
        vector<char> arr(size);
        int j=0;
        for(int i=0;i<size;i++){
            if(s[i]=='*'){
                j--;
            }
            else
            {
                arr[j]=s[i];
                j++;
            }
        }
        string result="";
        for(int k=0;k<j;k++){
            result.push_back(arr[k]);
        }
        
     
        return result;
        */
    }
};