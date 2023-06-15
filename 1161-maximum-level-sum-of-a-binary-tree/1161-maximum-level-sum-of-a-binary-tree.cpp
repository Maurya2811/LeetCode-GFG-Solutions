// // BFS
// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode*> que;
//         que.push(root);
//         int resultLevel=0;
//         int currLevel =0;
//         int maxSum=INT_MIN;
       
//         while(!que.empty()){
//             int n=que.size();
//             int sum=0;
//             while(n--){
                
//                 TreeNode* temp = que.front();
//                 que.pop();
//                 sum += temp->val;
//                 if(temp->left)
//                 que.push(temp->left);
//                 if(temp->right)
//                 que.push(temp->right);
                
//             }
//             currLevel++;
            
//             if(sum> maxSum){
//                 maxSum = sum;
//                 resultLevel=currLevel;
//             }
            
//         }
//         return resultLevel;
//     }
// };

// DFS
class Solution {
public:
    map<int,int> mp;
    
    void solve(TreeNode* root, int level){
        if(!root)
            return;
        
        solve(root->left,level+1);
          mp[level]+=root->val;
        solve(root->right,level+1);
        
    }
    
    int maxLevelSum(TreeNode* root) {
        int max=INT_MIN;
        int sum=0;
    
        int finalLevel=0;
       solve(root,1);
        for(auto &x:mp){
            sum=x.second;
           
            if(sum>max){
                max=sum;
                finalLevel=x.first;
            }
        }
        return finalLevel;
    }
};