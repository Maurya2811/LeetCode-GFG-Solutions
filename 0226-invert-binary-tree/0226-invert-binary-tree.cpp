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
    
    void invertVal(TreeNode* p ){
        if(!p)
            return ;
        
        swap(p->left,p->right);
     // TreeNode* temp = p->left
     //  p->left = p->right;
     // p->right = temp;
        
         invertVal(p->left);
         invertVal(p->right);
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
       
        
        invertVal(root);
        
        return  root;
    }
};