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
       int height(TreeNode* root){
        if(!root)
        return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
          if(!root)
        return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        int diff = abs(leftHeight - rightHeight);
        
        bool ans;
         diff<=1 ? ans =true : ans=false ;
         
         bool leftAns = isBalanced(root->left);
         bool rightAns = isBalanced(root->right);
         
         return (ans && leftAns && rightAns);
    }
};