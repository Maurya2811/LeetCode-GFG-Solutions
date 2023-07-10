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
    int findDepth(TreeNode* root){
        if(!root)
            return 0;
     if(!root->left && !root->right)
         return 1;
     if(!root->left || !root->right)
     return 1+max(findDepth(root->left),findDepth(root->right));
       
      return 1+ min(findDepth(root->left),findDepth(root->right));
    }
     
    
    int minDepth(TreeNode* root) {
      return findDepth (root);
    }
};