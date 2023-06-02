class Solution {
public:
    typedef long long LL;
    void dfs(int u,unordered_map<int,vector<int>> &adj ,unordered_set<int>&visited){
     
        visited.insert(u);
        
      
      for(auto &v : adj[u]){
          if(visited.find(v)==visited.end()){
             dfs(v,adj,visited);
          }
      }
        
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
       unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                LL x1=bombs[i][0];
                LL y1=bombs[i][1];
                LL r=bombs[i][2];
                
                LL x2=bombs[j][0];
                LL y2=bombs[j][1];
                
                
                if((LL(r*r)) >= ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))){
                    
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        unordered_set<int> visited;
        for(int i=0;i<n;i++){
           dfs(i,adj,visited);
            int temp=visited.size();
            ans = max(ans,temp);
            visited.clear();
        }
        return ans;
    }
};