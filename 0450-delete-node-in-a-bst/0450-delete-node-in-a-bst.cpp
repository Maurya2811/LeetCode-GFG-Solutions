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
    
    TreeNode* findNodeInBst(TreeNode* root, int key){
        if(root==NULL)
            return NULL;
        
        if(root->val==key){
            return root;
        }
        if(root->val<key){
          return findNodeInBst(root->right,key);
        }
           return findNodeInBst(root->left,key);     
    }
    
    int findMax(TreeNode* node){
        // if(!node)
        //     return -1;
        
        while(node->right){
            node=node->right;
        }
        return node->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root==NULL )
            return NULL;
        
        if(root->val == key){
             // TreeNode* temp = findNodeInBst(root,key);
    
                if(!root->left && !root->right){
                        delete root;
                        return NULL;
                    }
               else if(root->left && !root->right){
                        TreeNode* child = root->left;
                         delete root;
                        return child;
                     }  
               else if(!root->left && root->right){
                        TreeNode* child = root->right;
                         delete root;
                        return child;
                     }
               else{
                   // root has both child;
                   // Replacing with predecessor
                   int inOrderPrede = findMax(root->left);
                     
                     root->val = inOrderPrede;
                   root->left = deleteNode(root->left,inOrderPrede);
                   return root;
               }
         }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }
       return root;       
    }
};