//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void  BFS(unordered_map<int,vector<int>>adj,int u,vector<bool>&visited,vector<int>&result){
      queue<int> que;
       que.push(u);
       visited[u]=true;
       result.push_back(u);
       
       while(que.size()){
           int u = que.front();
           que.pop();
           
           for(auto &v:adj[u]){
               if(!visited[v]){
                   que.push(v);
                    visited[v]=true;
                    result.push_back(v);
               }
           }
       }
      
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        // Code here
          unordered_map<int,vector<int>>adj;
        for(int i=0;i<V;i++){
            
          for(auto it = mp[i].begin();it != mp[i].end();it++){
              adj[i].push_back(*it);
          }
        }
        vector<bool>visited(V,false);
        vector<int> result;
        BFS(adj,0,visited,result);
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends