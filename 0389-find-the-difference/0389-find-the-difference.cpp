class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};
        
        for(char &ch:s){
            arr[ch-'a']++;
        }
        for(char &ch:t){
            arr[ch-'a']--;
            if(arr[ch-'a'] <0)
                return ch;
        }
        return -1;
    }
};