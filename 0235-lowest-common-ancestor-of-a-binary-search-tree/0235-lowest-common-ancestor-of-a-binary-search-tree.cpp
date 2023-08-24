/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* &p, TreeNode* &q) {
      // case-1           
        if(p->val < root->val && q->val < root->val){
          return  lowestCommonAncestor(root->left , p,q);
        }
    // Case-2 
        if(p->val > root->val && q->val > root->val){
          return  lowestCommonAncestor(root->right , p,q);
        }
    // Case 3 and Case 4
        
   //     if(p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val)
        return root ;
        
    }
};