// // BFS
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int maxi=INT_MIN, lvl=0, res=0;

        while(!q.empty()){
            lvl++;
            int size=q.size();
            int sum=0;
            for(int i=0; i<size; i++){
                auto node=q.front();
                q.pop();
                sum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(sum>maxi){
                res=lvl;
                maxi=sum;
            }
        }

        return res;
    }
};

// DFS
/*
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
*/