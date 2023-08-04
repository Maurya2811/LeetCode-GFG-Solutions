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
    bool hasPathSum(TreeNode* root, int &targetSum) {
        if(!root)
            return false;
        
        if(!root->left && !root->right ){
            if(targetSum-root->val == 0)
                return true;
            else 
                return false;
        }
        
        targetSum-=root->val ;
        
    bool left =    hasPathSum(root->left,targetSum);
     bool right =   hasPathSum(root->right,targetSum);
        
        if(left || right)
            return true;
        
        targetSum+=root->val ;
        
        return (left || right);
    }
};