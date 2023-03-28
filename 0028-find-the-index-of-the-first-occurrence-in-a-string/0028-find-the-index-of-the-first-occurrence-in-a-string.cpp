class Solution {
public:
    int strStr(string haystack, string needle ) {
          // Needle in Heystack
          int haystackSIZE=haystack.length();
          int needleSIZE=needle .length();
        if(needle .length()>haystack.length())
        return -1;
       int j=0,l;
        for(int i=0; i< haystackSIZE - needleSIZE + 1 ;i++)
        {
           for(int j=0;j<needleSIZE;j++)
           {
               if(needle[j]!=haystack[i+j])
               {
                   break;
               }
               if(j==needleSIZE-1)
               return i;
           }
        } 
       
        return -1;
        // return haystack.find(needle) != string::npos ? haystack.find(needle): -1;
    }
};