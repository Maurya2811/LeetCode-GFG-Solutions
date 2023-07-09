class Solution {
public:
    int largestVariance(string s) {
        bool freq[26]={false};
        for(char x:s){
            freq[x-'a']=true;
        }
        int result=0;
        for( char i ='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(freq[i-'a'] && freq[j-'a']){
                    int freqCount1 =0;
                     int freqCount2 =0;
                    bool pastSeen = false;
                    for(char &ch:s){
                        if(i==ch){
                           freqCount1++; 
                        }
                        if(j==ch){
                           freqCount2++;
                            pastSeen =true;
                        }
                        if(freqCount2>0){
                            result = max(result,freqCount1-freqCount2);
                        }else{
                            if(pastSeen){
                                result = max(result,freqCount1-1);  
                            }
                        } 
                        if(freqCount1<freqCount2){
                            
                                    freqCount1 =0;
                                    freqCount2 =0;
                        }
                    }
                }
            }
        }
        return result;
    }
};