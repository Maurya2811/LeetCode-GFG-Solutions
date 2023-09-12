/*
class Solution {
public:
    int minDeletions(string &s) {
        int freq[26]={0};
        
        for(char &ch:s){
            freq[ch-'a']++;
        }
        
        sort(freq,freq+26);
        int result=0;
        for(int i=24; i>=0 && freq[i]>0 ; i-- ){
            if(freq[i]>=freq[i+1]){
                
                int prev = freq[i];
                
                freq[i] = max(0,freq[i+1]-1);
                
                result+= prev-freq[i];
            }
        }
        return result;
    }
};
*/

// 2nd Approach

class Solution {
public:
    int minDeletions(string &s) {
        int freq[26]={0};
        
        for(char &ch:s){
            freq[ch-'a']++;
        }
        
       unordered_set<int> hashSet ;
        int result=0;
        for(int i=0; i<=25 ; i++){
                while(freq[i]>0 && hashSet.find(freq[i])!=hashSet.end()){
                    freq[i]--;
                    result++;
                }
            hashSet.insert(freq[i]);
        }
        return result;
    }
};
