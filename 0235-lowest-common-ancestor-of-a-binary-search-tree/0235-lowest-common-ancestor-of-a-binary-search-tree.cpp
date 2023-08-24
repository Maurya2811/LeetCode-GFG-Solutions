// Recursive
/*
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
*/
// Iterative
class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (true) {
            if (p->val < node->val && q->val < node->val)
                node = node->left;
            else if (p->val > node->val && q->val > node->val)
                node = node->right;
            else
                break;    
        }
        return node;
    }
};