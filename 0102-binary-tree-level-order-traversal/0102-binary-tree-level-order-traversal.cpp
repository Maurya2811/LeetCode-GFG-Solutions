
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        if(!root)
            return {};
        
           vector<vector<int>> ans;
          queue<TreeNode*> q;
          q.push(root);
        
        while(q.size()){
            int size = q.size();
              vector<int> vec;
               for(int i=0;i<size;i++){
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