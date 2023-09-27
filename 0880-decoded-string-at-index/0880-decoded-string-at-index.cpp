class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        int n = s.length();
        
        long long size = 0;
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                size++;
            }else{
                size*= s[i]-'0';
            }
        }
        
        for(int i=n-1;i>=0;i--){
            
            k=k%size;
            
            if(k==0 && isalpha(s[i]))
                return string(1,s[i]);
            else if(isalpha(s[i])){
                size--;
            }else{
                size/=s[i]-'0';
            }
            
        }
        return "";
    }
};