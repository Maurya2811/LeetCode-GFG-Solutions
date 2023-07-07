class Solution {
public:
    int n;
    
    int findMaxKeyCount (string &answerKey,int &k,char key){
         int keyCount=0,maxLen =0;
        int i=0,currLen=0;
        for(int j=0;j<n;j++){
            if(answerKey[j]==key){
                keyCount++;
                while(keyCount >k){
                   
                    if(answerKey[i]==key){
                        keyCount--;
                    }
                     i++;
                }
               
            }
         currLen = j-i+1;
          maxLen = max(maxLen,currLen);
        }
        return maxLen;
        
    }
    
    
    
    int maxConsecutiveAnswers(string &answerKey, int &k) {
           n= answerKey.length();
        
        return max(findMaxKeyCount(answerKey,k,'T'),findMaxKeyCount(answerKey,k,'F'));
       
    }
};