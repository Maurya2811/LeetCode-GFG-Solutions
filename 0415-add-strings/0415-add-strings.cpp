class Solution {
public:
    void summation(string &num1,int s1, string &num2,int s2,int carry,string &ans){
        // Base Case
         
        if(s1<0 && s2<0){
            if(carry){
                ans+=to_string(carry);
            }
           return;
        }
            
        // solving one case
             
        int n1= s1<0 ? 0 : num1[s1]-'0';
        int n2= s2<0 ? 0 : num2[s2]-'0';
        int sum=n1+n2+carry;
        ans+= (sum)%10 +'0';
        carry = sum/10;
        
        summation(num1,s1-1,num2,s2-1,carry,ans);
         
        
    }
    string addStrings(string &num1, string &num2) {
        string ans="";
        summation(num1,num1.length()-1,num2,num2.length()-1,0,ans);
         reverse(ans.begin(),ans.end());
        return ans;
    }
};