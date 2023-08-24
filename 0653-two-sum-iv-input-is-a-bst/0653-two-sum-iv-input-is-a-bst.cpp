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
    
    int findTarget( TreeNode *root, int sum)
    {
        if(root==nullptr) return 0;
        
        if(hash.find(sum-(root->val))!=hash.end()) return 1;
        else
        {
            hash.insert({root->val});
        }
       return  findTarget(root->left , sum) || findTarget(root->right , sum);
    }
};
