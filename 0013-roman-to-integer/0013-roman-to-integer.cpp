class Solution {
public:
   
   map<char,int> mp ={ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
    int romanToInt(string s) {
        int ans=0;
        int i=0;
        int n=s.length();
        while(i<n){
            if(s[i]=='I'){
                if(i<n && s[i+1]=='V'){
                    ans+=4;
                    i+=2;
                    continue;
                }else if(i<n && s[i+1]=='X'){
                    ans+=9;
                    i+=2;
                    continue;
                }
            }else if(s[i]=='X'){
                if(i<n && s[i+1]=='L'){
                    ans+=40;
                    i+=2;
                    continue;
                }else if(i<n && s[i+1]=='C'){
                    ans+=90;
                    i+=2;
                    continue;
                }
            }else if(s[i]=='C'){
                if(i<n && s[i+1]=='D'){
                    ans+=400;
                    i+=2;
                    continue;
                }else if(i<n && s[i+1]=='M'){
                    ans+=900;
                    i+=2;
                    continue;
                }
            }
                // ans+= 
                ans+=mp[s[i]];
                i++;
        }
        return ans;
    }
};