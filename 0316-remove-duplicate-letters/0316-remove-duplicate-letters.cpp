class Solution {
public:
    
   
    
    
    string removeDuplicateLetters(string s) {
        
        int n=s.length();
        
        bool arr[26]={false};
        vector<int> index (26,-1);
        
        for(int i=0;i<n;i++){         
            index[s[i]-'a']=i;
        }
       
        string st="";
        
        for(int i=0;i<n;i++){
            
            if(arr[s[i]-'a']){
                continue;
            }
            
            char ch=s[i];
            
            while( st.length()>0 && ch < st.back() && index[st.back()-'a'] > i){
                
                arr[st.back()-'a']=false;
                st.pop_back();   
            }
            
           st.push_back(ch);      
            arr[ch-'a']=true;
        }
        return st;
    }
};