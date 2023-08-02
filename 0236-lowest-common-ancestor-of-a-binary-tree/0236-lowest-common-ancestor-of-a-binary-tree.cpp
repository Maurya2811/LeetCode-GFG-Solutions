
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor (root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(!left && ! right)
            return NULL;
        else if(!left && right)
            return right;
        else if(left && !right)
            return left;
        else // left && right
            return root;
        
    }
};