class Solution {
public:
    int n;
    int solve(vector<int>& nums,vector<bool> &visited,int operation,  unordered_map<vector<bool>,int>&dp){
        int maxAns=0;
        if(dp.find(visited)!=dp.end()){
            return dp[visited];
        }
         for(int i=0 ; i<n-1;i++){
             if(visited[i]==true)
                 continue;
             for(int j=i+1;j<n;j++){
                 if(visited[j]==true)
                     continue;
                 
                 visited[i]=true;
                 visited[j]=true;
                 
                 int score = operation * __gcd(nums[i],nums[j]) +  solve(nums,visited,operation+1,dp);
                 // int remaining =  solve(nums,visited,operation+1);
                 // maxAns = max(maxAns,score+remaining);  
               maxAns = max(maxAns,score);  

                    
                     visited[i]=false;
                 visited[j]=false;  
             }
         }
        return dp[visited]=maxAns;
       
    }
    
    
    int maxScore(vector<int>& nums) {
        n = nums.size();
        unordered_map<vector<bool>,int>dp;
        
        vector<bool> visited(n,false);
        
        return solve(nums,visited,1,dp);
    }
};