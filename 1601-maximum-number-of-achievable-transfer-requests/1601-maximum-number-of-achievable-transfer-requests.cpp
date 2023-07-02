class Solution {
public:
    int result = INT_MIN;
    
    void solve(int idx,int count, vector<vector<int>>& requests, vector<int>&resultant ){
        if(idx>= requests.size()){
            for(int x:resultant){
                if(x!=0)
                    return;
            }
            result = max(result,count);
            return;
        }
        
        int from = requests[idx][0];
        int to = requests[idx][1];
        
        resultant[from]--;
        resultant[to]++;

       solve(idx+1,count+1,requests,resultant);
        
        resultant[from]++;
        resultant[to]--;
        solve(idx+1,count,requests,resultant);
        
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> resultant(n,0);
        
        solve(0,0,requests,resultant);
        return result;
    }
};