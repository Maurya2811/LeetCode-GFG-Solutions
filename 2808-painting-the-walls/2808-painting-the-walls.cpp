class Solution {
public:
 int n;
 int dp[501][501];
 
 int solve(int idx, vector<int>&cost , vector<int>&time , int walls){
     if(walls <= 0 )
     return 0;

     if(idx>= n){
         return 1e9;
     }

     if(dp[idx][walls]!=-1)
     return dp[idx][walls];

     int paint = cost[idx] + solve(idx+1,cost,time, walls -1 - time[idx]);


     int not_paint = solve(idx+1,cost,time, walls );

     return dp[idx][walls] = min(paint, not_paint);
 }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int  walls = cost.size();
         n= walls;

         memset(dp,-1,sizeof(dp));

        return solve(0,cost,time,walls);
    }
};