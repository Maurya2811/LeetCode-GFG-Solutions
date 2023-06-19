class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n= gain.size();
        vector<int> v(n+1,0);
        int x=0;
    
        for(int i=0;i<n;i++){
             x+=gain[i];
            v[i+1]=x;
        }
        sort(v.begin(),v.end());
       
        return v[n];    }
};