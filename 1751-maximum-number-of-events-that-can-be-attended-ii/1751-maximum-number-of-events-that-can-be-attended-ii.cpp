//Approach-2 (Using Recursion + Memo) using Binary Search for next event - T.C. - O(n⋅k⋅log(n))
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int k) {
        
        if(k <= 0 || i >= n)
            return 0;
        
        int start = events[i][0];
        int endt   = events[i][1];
        int value = events[i][2];
        
        if(t[i][k] != -1)
            return t[i][k];
        
        // finding the next event which we can attend
        vector<int> temp = {endt, INT_MAX, INT_MAX};
        int j = upper_bound(events.begin(), events.end(), temp) - events.begin();
        
        int take = value + solve(events, j, k-1);
        int skip = solve(events, i+1, k);
        
        return t[i][k] = max(take, skip);
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        
        n = events.size();
        
        t.resize(n+1, vector<int>(k+1, -1));
        
        return solve(events, 0, k);
    }
};

