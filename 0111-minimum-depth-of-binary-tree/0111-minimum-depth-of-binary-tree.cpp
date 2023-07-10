 // Using BFS

// Use this type of BFS when minimum depth is needed
/*
class Solution {
public:
    int minDepth(TreeNode* root) {
          if(!root)
               return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth =1;
        while(!que.empty()){
            
            int n= que.size();  
            
            while(n--){
                TreeNode* temp = que.front();
                que.pop();
                
                if(!temp->left && !temp->right){
                    return depth;
                }
                
                if(temp->left){
                    que.push(temp->left);
                }
                 if(temp->right){
                    que.push(temp->right);
                }
            }
            depth++;        
        }
        return -1;
    }
};
*/
// Using DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
          if(!root)
               return 0;
          if(!root->left && !root->right ){
                    return 1;
                }
        int left_depth = root->left ? minDepth(root->left) : INT_MAX;
        int right_depth = root->right ? minDepth(root->right) : INT_MAX;
        
        return 1 + min(left_depth ,right_depth);
    }
};



