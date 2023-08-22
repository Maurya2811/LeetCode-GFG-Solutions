class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
         while(columnNumber){
             columnNumber--;
             char temp = columnNumber%26 +'A';
             ans =  temp + ans;
             columnNumber/=26;
         }
        return ans;
    }
};