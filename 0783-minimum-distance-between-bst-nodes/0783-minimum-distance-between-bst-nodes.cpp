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
     TreeNode* prevNode;
    void findMinDiff(TreeNode* root, int &minDiff ){
        if(!root )
            return ;
        
         findMinDiff(root->left,minDiff);
        
        if(prevNode){
            minDiff = min(minDiff , abs(root->val - prevNode->val));
        }
         prevNode = root;
       
        
        findMinDiff(root->right,minDiff);
    }
    int minDiffInBST(TreeNode* root) {
          int minDiff=INT_MAX;
         findMinDiff (root,minDiff);
        return minDiff;
    }
};