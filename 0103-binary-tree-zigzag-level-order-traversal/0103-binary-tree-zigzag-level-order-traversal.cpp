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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
         vector<vector<int>>ans;
          queue<TreeNode*> q;
          q.push(root);
        bool direction = false;   // true -> left to right
                                 // false-> right to left
        
        while(q.size()){
            int size = q.size();
              vector<int> vec;
              for(int i=0;i<size;i++){
                 TreeNode* temp = q.front();
                  q.pop();
                  vec.push_back(temp->val);
                  if(temp->left){
                      q.push(temp->left);
                  }
                  if(temp->right){
                      q.push(temp->right);
                  }
              }
                
               if(direction){
                  reverse(vec.begin(),vec.end()); 
               }
               ans.push_back(vec);
                direction = !direction; 
               
            } 
        return ans;
    }
};