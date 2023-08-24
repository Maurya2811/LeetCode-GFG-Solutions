class Solution {
public:
    string multiply(string num1, string num2) {
         if (num1 == "0" || num2 == "0") return "0";
        int len1= num1.length();
        int len2= num2.length();
         
          int len = len1+len2;
       vector<int> res(len,0);
        
        int carry=0;
        
        for(int j=0;j<len2;j++){
            int n2 = num2[len2-1-j]-'0';                
            for(int i=0;i<len1;i++){
                int n1 = num1[len1-1-i]-'0';
                res[len-1-i-j]+= n1*n2+carry;
                carry = res[len-1-i-j]/10;
                res[len-1-i-j]%=10;
            }
            if(carry){
                res[len-1-j-len1]=carry;
                carry=0;
            }
        }
        string ans="";
        int i=0;
        while(res[i]==0){
            i++;
        }
        while(i<len){
            ans += res[i]+'0';
            i++;
        }

       return ans; 
    }
};