
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        if(!root)
            return {};
        
           vector<vector<int>> ans;
          queue<TreeNode*> q;
          q.push(root);
        
        while(1){
            int size = q.size();
              if(size==0)
                  return ans;
              vector<int> vec;
               while(size--){
                     TreeNode* temp = q.front();
                       q.pop();
                     vec.push_back(temp->val);
                   
                   if(temp->left){
                       q.push(temp->left);
                   }
                    if(temp->right){
                       q.push(temp->right);
                   }
                  
               }
            ans.push_back(vec);
                
        }
        
        
        return ans;
    }
};