class Solution {
public:
    
    int maxVowels(string s, int k) {
        int max_count=0;
        int count=0;
        auto isVowel = [&](char c){
            return c== 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int i=0,j=0,n=s.length();
        while(j<n){
            if(isVowel(s[j]))
                count++;
               
            if(j-i+1==k){
                max_count=max(max_count,count);
                
                if(isVowel(s[i])){
                    count--;
                }
                i++;
            }
            
            j++;
        }
        return max_count;
    }
};