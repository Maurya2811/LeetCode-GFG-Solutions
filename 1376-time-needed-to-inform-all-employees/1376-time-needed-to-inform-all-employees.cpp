class Solution {
public:
     int maxTime=0;
    
    void BFS(int curr_Emp,unordered_map<int,vector<int>> &adj, vector<int>& informTime){
       
        queue<pair<int,int>>que;
        que.push({curr_Emp,0});
        
        while(!que.empty()){
            pair<int,int> curr = que.front();
            que.pop();
                curr_Emp = curr.first;
              int currTime = curr.second;
            
            maxTime=max(maxTime,currTime);
            
            for(int &v: adj[curr_Emp]){
           int temp= currTime + informTime[curr_Emp];
         
           que.push({v,temp});
            
        }
            
        }
       
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj;
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        
       
        
        BFS(headID,adj,informTime);
        
        
        
        return maxTime;
    }
};