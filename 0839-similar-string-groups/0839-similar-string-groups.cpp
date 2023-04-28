// 3 Approaches 
// 1. DFS
// 2. BFS
// 3. Disjoint Sets

class Solution {
public:
    
    bool isSimilar(string &s1,string &s2){
        int diff=0;
        int m=s2.length();  // Strings are of equal lengths
         for(int i=0;i<m;i++){
             if(s1[i]!=s2[i])
                 diff++;
         }
        return diff==0 || diff==2;
    }
     void BFS(int i, unordered_map<int,vector<int>> &adj, vector<bool> &visited){
         queue<int> q;
         
         q.push(i);
          visited[i]=true;
         
         while(!q.empty()){
         int u=q.front();
         q.pop();
         for(int &v:adj[u]){
             if(!visited[v]){
                 q.push(v);
                 visited[v]=true;             
             }
         }
         }
    }
    
//     void DFS(int u, unordered_map<int,vector<int>> &adj, vector<bool> &visited){
//           visited[u]=true;
//           for(int &v: adj[u]){
//              if(!visited[v]){
//                  DFS(v,adj,visited);
//              }
//           }
        
//     }
        
        
    
        
    int numSimilarGroups(vector<string>& strs) {
      int n = strs.size();
       unordered_map<int,vector<int>> adj;
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int count=0;
          
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // DFS(i,adj,visited);
                  BFS(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};