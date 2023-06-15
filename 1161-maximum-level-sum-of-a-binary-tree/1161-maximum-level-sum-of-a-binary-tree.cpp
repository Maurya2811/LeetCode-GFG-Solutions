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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int resultLevel=0;
        int currLevel =0;
        int maxSum=INT_MIN;
       
        while(!que.empty()){
            int n=que.size();
            int sum=0;
            while(n--){
                
                TreeNode* temp = que.front();
                que.pop();
                sum =sum + temp->val;
                if(temp->left)
                que.push(temp->left);
                if(temp->right)
                que.push(temp->right);
                
            }
            currLevel++;
            
            if(sum> maxSum){
                maxSum = sum;
                resultLevel=currLevel;
            }
            
        }
        return resultLevel;
    }
};