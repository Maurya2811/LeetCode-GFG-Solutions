class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          sort(begin(intervals),end(intervals));
        int n = intervals.size();
        int i=0,j=1;
        int count =0;
        
        while(j<n){
            int currStart = intervals[i][0];
             int currEnd = intervals[i][1];
            int nextStart = intervals[j][0];
             int nextEnd = intervals[j][1];
            
            if(currEnd <= nextStart) // Safe
            {
               i=j;
               
                
            }
            else if(currEnd > nextEnd ){
                i=j;
                count++;
                    
            }
            else if(nextEnd >= currEnd){
                 
                count++;
            }
            j++;
            
        }
        return count;
    }
};