class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
          vector<int> StartEnd(n+1,0);
        
        for(int i=0;i<=n;i++){
             int start =  max(0, i-ranges[i]);
             int end =    min(n ,  i+ranges[i]);
            
            StartEnd[start] = max( StartEnd[start], end );
        }
        
        int taps=0;
        int currEnd =0;
        int maxEnd =0;
        
        for(int i=0;i<=n;i++){
            
            if(i>maxEnd)
                return -1;
            
            if(i>currEnd){
                taps++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd, StartEnd[i]);
        }
        
        return taps;
    }
};