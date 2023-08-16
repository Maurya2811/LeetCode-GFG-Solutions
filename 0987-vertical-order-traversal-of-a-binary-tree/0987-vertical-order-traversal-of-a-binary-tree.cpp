/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        map< int , map<int,vector<int>>> mp;
        
        queue< pair<int,pair<int,TreeNode*>>> que;
        
        que.push({0,{0,root}});
        while(!que.empty()){
              int dis = que.front().first ;
              int level = que.front().second.first;     
            TreeNode* temp = que.front().second.second;
             que.pop();
             mp[dis][level].push_back( temp->val);
            
            if(temp->left){
                que.push({dis-1,{level+1,temp->left}});
            }
            if(temp->right){
                que.push({dis+1,{level+1,temp->right}});
            }
        }
        vector<vector<int>>ans;
        for(auto &i:mp){
             vector<int> temp;
            for(auto &j:i.second){  
                auto x = j.second ;
                sort(x.begin(),x.end());
               // for(int &w:x){
               //     temp.push_back(w);
               // }
                temp.insert(temp.end(),x.begin(),x.end());      
            }
            ans.push_back(temp);
        }
        return ans;
    }
};