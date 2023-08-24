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
    
    void makeInOrder(TreeNode* root, vector<int>& vec){
        if(root==NULL)
            return;
        
        makeInOrder(root->left,vec);
        vec.push_back(root->val);
        makeInOrder(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
       
        vector<int> vec ;
        makeInOrder(root,vec);
        int s=0, e= vec.size()-1;
        
        while(s<e){
            int sum = vec[s]+vec[e];
            
            if(sum==k)
                return true;
            
            if(sum<k){
                s+=1;
            }else{
                e-=1;
            }
        }
        return false;
    }
};