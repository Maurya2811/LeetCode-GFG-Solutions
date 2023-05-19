class Solution {
public:
    
    bool checkIsBipartite(int curr,vector<vector<int>>& adj,vector<int>&color,int currColor){
        color[curr]=currColor;
        for(auto &v: adj[curr]){
            
            if(color[curr]==color[v])
                return false;
            if(color[v]==-1){
                int colorOf_V= 1- currColor;
              if(checkIsBipartite(v,adj,color,colorOf_V )==false)
                  return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        // Color green =>>  0
        //        red  =>>  1
        for(int i=0;i<n;i++){
           
            if(color[i]==-1)
                if(checkIsBipartite(i,graph,color,0)==false)
                    return false;
        }
        return true;
        
    }
};