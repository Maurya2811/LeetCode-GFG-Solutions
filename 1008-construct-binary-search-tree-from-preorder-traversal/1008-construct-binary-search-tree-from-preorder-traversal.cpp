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
    int n;
      
    
    // Please Note that the index is passed by reference 
    
    TreeNode* solve(int &i,vector<int> &preorder, int &mini, int &maxi){
        if(i>=n)
            return NULL;
        
        if(preorder[i]< mini || preorder[i]> maxi)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = solve(i,preorder,mini, root->val);
        root->right = solve(i, preorder,root->val, maxi);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         n = preorder.size();
        int i=0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return solve(i,preorder,mini,maxi);
    }
};