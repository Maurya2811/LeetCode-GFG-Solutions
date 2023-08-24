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
    bool solve(TreeNode* root , long long LB , long long UB){
        if(!root){
            return true;
        }
        if(root->val < UB && root->val > LB){
            return solve(root->left,LB,root->val) && solve(root->right,root->val,UB);
        }else
            return false;
    }
    bool isValidBST(TreeNode* root) {
       
        return solve(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
    }
};