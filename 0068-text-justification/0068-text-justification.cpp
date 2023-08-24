class Solution {
public:
    int MaxWidth,n;
    
   
    string findLine(int &i,int &j,int &eachGaddheSpace,int extraSpace,vector<string> &words){
         string Line="";
        
        for(int k =i ; k<j;k++){
            Line += words[k];
            
           if(k==j-1){ // Last word of my Line
               // No Space after last word of my line
               break;
           } 
            for(int x=1 ; x<=eachGaddheSpace;x++){
                Line+=" ";
            }
            if(extraSpace){
                Line+=" ";
               extraSpace--; 
            }
        }
          while(Line.length()<MaxWidth){
                Line+=" ";
            }
        return Line;
    } 
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
           MaxWidth =maxWidth;
           n = words.size();
        vector<string> result;
        
        int i=0;
        
        while(i<n){
            
            int letterCounts = words[i].length();
            int j=i+1;
             int gaddhe =0; // space between two words
            
            
            while(j<n && words[j].length()+1+ gaddhe+letterCounts <= maxWidth ){
                  letterCounts += words[j].length();
                   gaddhe ++;
                   j++;
            }
             int remainingSpaces = maxWidth - letterCounts ;
            
            int eachGaddheSpace = gaddhe == 0 ? 0:remainingSpaces / gaddhe ;
            int extraSpace = gaddhe == 0 ? 0:remainingSpaces % gaddhe ;
            
            if(j==n){
                eachGaddheSpace =1;
                  extraSpace =0;
            }
            
            result.push_back(findLine(i,j,eachGaddheSpace,extraSpace,words));
            i=j;
        }
            return result;
    }
};