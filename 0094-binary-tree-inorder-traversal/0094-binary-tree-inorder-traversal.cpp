// Recursive
/*
class Solution {
public:
    
    void solve(TreeNode* root,vector<int> &result){
        if(root==NULL){
            return;
        }
        solve(root->left,result);
        result.push_back(root->val);
        solve(root->right,result);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
         solve(root,result);
        return result;
    }
};
*/

class Solution {
public:
    
    void solve(TreeNode* root,vector<int> &result){
       stack<TreeNode*> s;
          TreeNode* curr = root;
        while (curr  || !s.empty()) {
            while (curr ) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        
    }
        
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
         solve(root,result);
        return result;
    }
};