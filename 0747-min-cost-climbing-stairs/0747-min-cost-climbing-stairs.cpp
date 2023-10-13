class Solution {
public:
int n;
    vector<int> dp, cost;
    int f(int i){
        if (i>=n-1) return 0;
        if (dp[i]!=2e6) return dp[i];
        return dp[i]=min(cost[i]+f(i+1), cost[i+1]+f(i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost=cost;
        n=cost.size();
        dp.assign(n, 2e6);
        return f(0);
    }
};