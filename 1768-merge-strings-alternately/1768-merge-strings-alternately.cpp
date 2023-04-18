class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string s="";
        while(i<word1.length() && j<word2.length()){
            s.push_back(word1[i++]);
            s.push_back(word2[j++]);
        }
        while(i<word1.length()){
            s.push_back(word1[i++]);
        }
        while(j<word2.length()){
            s.push_back(word2[j++]);
        }
        return s;
    }
};