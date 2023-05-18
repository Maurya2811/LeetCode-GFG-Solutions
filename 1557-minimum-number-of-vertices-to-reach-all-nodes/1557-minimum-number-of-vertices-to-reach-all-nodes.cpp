class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Nodes which has indgree 0, must be included..
         vector<bool> indegree(n,false);
        
        for(auto &edge : edges ){
            indegree[edge[1]]=true;
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==false)
                ans.push_back(i);
        }
        return ans;
    }
};