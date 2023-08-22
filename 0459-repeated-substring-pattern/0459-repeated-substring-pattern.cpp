class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n  = s.length();
        
        for(int i=n/2;i>=1;i--){
            if(n%i==0){
                 string temp = s.substr(0,i);
                int times = n/i;
                string substr ="";
                while(times--){
                    substr+=temp;
                } 
            if(substr== s)
                return true;
            }  
        }
        return false;
    }
};