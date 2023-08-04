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
    
    void hasPathSum(TreeNode* root, int &targetSum,vector<int>&path, vector<vector<int>>&ans) {
        if(!root)
            return ;
        
        if(!root->left && !root->right ){
            if(targetSum-root->val == 0){     
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
                return ;
            }      
            else{ 
                  
                return ;
            }
        }
        
        targetSum-=root->val ;
        path.push_back(root->val);
        
        hasPathSum(root->left,targetSum,path,ans);
        hasPathSum(root->right,targetSum,path,ans);
        
        
        
        targetSum+=root->val ;
        path.pop_back();
        return ;
        
    }
    
//     bool hasPathSum(TreeNode* root, int &targetSum,vector<int>&path, vector<vector<int>>&ans) {
//         if(!root)
//             return false;
        
//         if(!root->left && !root->right ){
//             if(targetSum-root->val == 0){
//                 path.push_back(root->val);
//                 ans.push_back(path);
//                 path.pop_back();
//                 return true;
//             }
//             else 
//                 return false;
//         }
        
 
//         targetSum-=root->val ;
//         path.push_back(root->val);
        
//     bool left =    hasPathSum(root->left,targetSum,path,ans);
//      bool right =   hasPathSum(root->right,targetSum,path,ans);
        
// //         if(left || right){
            
// //             return true;
// //         }
        
//         targetSum+=root->val ;
//         path.pop_back();
        
//         return (left || right);
//     }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
       vector<vector<int>> ans;
        if(!root)
            return {};
        
        hasPathSum(root,targetSum ,path,ans);
        return ans;
    }
};