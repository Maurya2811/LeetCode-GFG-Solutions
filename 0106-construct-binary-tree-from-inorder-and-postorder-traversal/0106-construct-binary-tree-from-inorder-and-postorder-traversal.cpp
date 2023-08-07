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
     int n;
    unordered_map<int,int> mp;
//     int findPos(vector<int>& inorder,int inStart,int inEnd ,int val){
        
        // for(int i=inStart;i<=inEnd;i++){
        //     if(inorder[i]==val){
        //         return i;
        //     }
        // }
        // return -1;
//     }
      TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int &postIndex,int inStart,int inEnd){
          if(postIndex < 0 || inStart>inEnd){
              return NULL;
          }
          int data = postorder[postIndex--];
          TreeNode* node = new TreeNode(data);
          // int pos = findPos(inorder,inStart,inEnd,data);
           int pos = mp[data];     
          
           node->right = solve(postorder,inorder,postIndex, pos+1,inEnd);
          node->left = solve(postorder,inorder,postIndex, inStart, pos-1);
                  
          return node;
          
      }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         n=postorder.size();
        for(int x=0;x<n;x++){
            mp[inorder[x]]=x;
        }
          
        int postIndex=n-1;
     return solve(postorder,inorder,postIndex,0,n-1);

    }
};