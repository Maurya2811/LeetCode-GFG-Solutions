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
    int sum=0;
    void solve(TreeNode* root){
        if(!root){
            return ;
        }
     
        // if(!root->left && !root->right){
        //     root->val += sum;
        //     sum =  root->val;
        // }
     
        solve(root->right);
        root->val += sum  ;
        sum = root->val;
         solve(root->left);
        
        return ;
      
    }
    TreeNode* bstToGst(TreeNode* root) {   
        solve(root); 
        return root;
    }
};