
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
      TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preIndex,int inStart,int inEnd){
          if(preIndex >= n || inStart>inEnd){
              return NULL;
          }
          int data = preorder[preIndex++];
          TreeNode* node = new TreeNode(data);
          // int pos = findPos(inorder,inStart,inEnd,data);
           int pos = mp[data];       
          node->left = solve(preorder,inorder,preIndex, inStart, pos-1);
          node->right = solve(preorder,inorder,preIndex, pos+1,inEnd);
          
          return node;
          
      }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=preorder.size();
        for(int x=0;x<n;x++){
            mp[inorder[x]]=x;
        }
          
        int preIndex=0;
     return solve(preorder,inorder,preIndex,0,n-1);

    }
};