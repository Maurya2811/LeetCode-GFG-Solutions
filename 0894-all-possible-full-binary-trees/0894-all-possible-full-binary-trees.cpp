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
    unordered_map <int , vector<TreeNode*>> map;
    vector<TreeNode*> solve(int n){
         if(n&1==0){
            return {};
        }
        if(n==1){
            TreeNode* node = new  TreeNode(0);
            return {node};
        }
        
        if(map.find(n)!= map.end()){
            return map[n];
        }
        vector<TreeNode*> ans;
        for(int i=1;i<n ; i+=2){
            
            vector<TreeNode*> allLeftFBT = allPossibleFBT(i);
            vector<TreeNode*> allRightFBT = allPossibleFBT(n-i-1);
               
              for(auto &l: allLeftFBT){
                  for(auto &r: allRightFBT){
                      TreeNode* root = new  TreeNode(0);
                      root->left = l;
                      root->right = r;
                      ans.push_back(root);
                  }
              }
        }
        return  map[n] = ans;
            
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
          
       return solve(n);
    }
};