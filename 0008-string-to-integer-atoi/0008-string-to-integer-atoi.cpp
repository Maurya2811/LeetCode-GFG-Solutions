class Solution {
public:
    int myAtoi(string s) {
        int i=0,num=0;
        int sign=1; //positive

    // 1.  Ignore leading whitespaces
        while(s[i]==' '){
            i++;
        }
    // 2.  Determinig Sign
       if(i<s.length() && (s[i]=='+' || s[i]=='-')){
           sign = s[i]=='+' ? 1 : -1; 
           i++;
       }    
    // 3.  If digit found prepare "num"
       while(i<s.length() && isdigit(s[i])){
           if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')){
               return sign==-1 ? INT_MIN : INT_MAX ;
           }
           num=num*10 + (s[i]-'0');
           i++;
       }   
       return num * sign;
    }
};