class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n= gain.size();
      
        int x=0;
    int temp =0;
        for(int i=0;i<n;i++){
             x+=gain[i];
           temp = max(x,temp);
        }
     
       
        return temp;
    }
};