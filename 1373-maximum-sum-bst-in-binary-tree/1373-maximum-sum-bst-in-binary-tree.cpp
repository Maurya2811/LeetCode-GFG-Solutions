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

class Nodedata {
    public:
    
    bool validBST;
    int maxi ;
    int mini;
    int sum;
  
        Nodedata(){
            // this->validBST = false;
        }
        
        Nodedata(bool validBST, int maxi, int mini, int sum){
            this->validBST = validBST;
            this->maxi=maxi;
            this->mini=mini;
            this->sum=sum;
        }
};
class Solution {
public:
      
      Nodedata* findLargerBST(TreeNode* root,int &maxi){
          if(root==NULL){
              Nodedata* node = new Nodedata(true,INT_MIN,INT_MAX,0);
              return node;
          }
          
      Nodedata* leftAns = findLargerBST(root->left,maxi);
      Nodedata* rightAns = findLargerBST(root->right,maxi);
      
      Nodedata* currentAns = new Nodedata();
      
           
             
      if(leftAns->validBST && rightAns->validBST && 
         root->val > leftAns->maxi && root->val< rightAns->mini ){
         
             currentAns->validBST = true;
             currentAns->maxi = max(root->val,rightAns->maxi);
             currentAns->mini = min(root->val,leftAns->mini);
             currentAns->sum= root->val+ leftAns->sum + rightAns->sum;
             maxi = max(maxi,currentAns->sum);
            }
          else{
               currentAns->validBST = false;  
      }
      
      return currentAns;
      
    }
    
    int maxSumBST(TreeNode* root) {
          
        int maxi =0;
        findLargerBST(root,maxi);
    	return maxi;
    }
};