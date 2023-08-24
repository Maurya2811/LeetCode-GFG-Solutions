//Approach 1 
// Using InOrder Traversal and TwoPointer Approach
/*
class Solution {
public:
    
    void makeInOrder(TreeNode* root, vector<int>& vec){
        if(root==NULL)
            return;
        
        makeInOrder(root->left,vec);
        vec.push_back(root->val);
        makeInOrder(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
       
        vector<int> vec ;
        makeInOrder(root,vec);
        int s=0, e= vec.size()-1;
        
        while(s<e){
            int sum = vec[s]+vec[e];
            
            if(sum==k)
                return true;
            
            if(sum<k){
                s+=1;
            }else{
                e-=1;
            }
        }
        return false;
    }
};
*/

// 2nd Approach
// using HashSet and InOrderTraversal
class Solution {
public:
     unordered_set<int> hash;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        if(hash.find(k-root->val)!=hash.end())
        return true;
        else{
            hash.insert(root->val);
        }
         if(findTarget(root->left,k)==true)
           return true;
        
            return findTarget(root->right,k);
    }
};
