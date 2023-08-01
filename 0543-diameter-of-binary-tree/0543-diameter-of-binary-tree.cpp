/*

class Solution {
public:
   int maxDepth(TreeNode* root){
       if(root==NULL)
           return 0;
       
       return 1 + max(maxDepth(root->left),maxDepth(root->right));
   }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left)+maxDepth(root->right);
        
        return max(op1, max(op2,op3));
    }
};
*/
class Solution {
public:
   
    int Max =0;
    
    int maxDia(TreeNode* root){
         if(root==NULL)
            return 0;
        
        int op1 =  maxDia(root->left);
        int op2 =  maxDia(root->right);
        Max =  max(Max,op1+op2);
        
        return  1 + max(op1,op2);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
           maxDia(root);
       return Max;
    }
};