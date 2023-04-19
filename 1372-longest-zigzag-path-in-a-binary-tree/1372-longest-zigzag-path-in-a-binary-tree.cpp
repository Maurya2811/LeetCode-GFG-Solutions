// 2 Approaches Using Recursion

// 1 Approaches
class Solution {
public:
    int max_len =0;
  void  solve(TreeNode* root,int path,bool go_left){
        if(root==NULL){
            return ;
        }
        max_len = max(max_len,path);
        if(go_left == true){
           solve(root->left,path+1,false);
             solve(root->right,1,true);
        }
        else{
            solve(root->right,path+1,true);
             solve(root->left,1,false);
        }
        return ;
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root,0,1);
        solve(root,0,0);
        return max_len;
    }
};