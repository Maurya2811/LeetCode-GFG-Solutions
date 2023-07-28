//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
               if(root==NULL) return NULL;
            int curr=root->data;
            if(curr<n1 && curr<n2)
            return LCA(root->right,n1,n2);
            if(curr>n1 && curr >n2)
            return LCA(root->left,n1,n2);
            
            return root;
        }

};
//Function to find the lowest common ancestor in a BST.
// class Solution{
//     public:
    
//     bool findPath(Node* root, int n , vector<pair<Node*,int>>&path){
//         if(root == NULL){
//             return false;
//         }
        
//         path.push_back({root,root->data});
//         if(root->data == n)
//         return true;
        
//         if( findPath(root->left ,n,path)|| findPath(root->right ,n,path))
//           return true;
        
//      path.pop_back();   
//       return false;
//     }
      
//         Node* LCA(Node *root, int n1, int n2)
//         {
//             vector<pair<Node*,int>>path1,path2;
            
//             findPath(root,n1,path1);
//             findPath(root,n2,path2);
            
//             Node* ans=NULL;
//             for(int i=0;i<path1.size() && path2.size();i++){
//                 if(path1[i].second == path2[i].second)
//                   ans = path1[i].first;
//             }
//             return ans;
//         }
// };
   


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends