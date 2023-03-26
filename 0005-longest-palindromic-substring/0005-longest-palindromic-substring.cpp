// Optimize it by Using Dynamic Proggmg
class Solution {
public:
bool ispalindromic(string &s,int left , int right)
{
    while(left<right)
    {
        if(s[left] != s[right])
        return false;
        left++;
        right--;
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                // Finds all Substrings 
                // i -> start index 
                // j -> end index
                if(ispalindromic(s,i,j))
                {
                    string temp = s.substr(i,j-i+1);
                    if(temp.length()>ans.length())
                       ans=temp;
                }
            }
        }
        return ans;
    }
};