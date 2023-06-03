class Solution {
public:
     int maxTime=0;
    
    void DFS(int curr_Emp,unordered_map<int,vector<int>> &adj, vector<int>& informTime,int currTime){
        maxTime=max(maxTime,currTime);
        for(int &v: adj[curr_Emp]){
           int temp= currTime + informTime[curr_Emp];
           DFS(v,adj,informTime,temp);
            
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj;
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        
       
        
        DFS(headID,adj,informTime,0);
        
        
        
        return maxTime;
    }
};