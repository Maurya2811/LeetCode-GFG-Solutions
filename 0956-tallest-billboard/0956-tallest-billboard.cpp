class Solution {
public:
    int t[21][10002];
    int solve(int i,vector<int>&rods, int diff){
        if(i>=rods.size()){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        if(t[i][diff+5000]!=-1)
            return t[i][diff+5000];
        int takenLeft = rods[i]+ solve(i+1,rods,diff+rods[i]);
        int takenRight = rods[i]+ solve(i+1,rods,diff-rods[i]);
        int noTake = solve(i+1,rods,diff);
        
       return t[i][diff+5000]=max(takenLeft,max(takenRight,noTake));
    }
    int tallestBillboard(vector<int>& rods) {
        memset(t,-1,sizeof(t));
        return solve(0,rods,0)/2;
    }
};