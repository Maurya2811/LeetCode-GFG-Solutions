//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
     unordered_map<int,int> mp;
     int n;
      int findPos(int inorder[],int inStart,int inEnd ,int val){
        
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    
      Node* solve(int preorder[], int inorder[],int &preIndex,int inStart,int inEnd){
          if(preIndex >= n || inStart>inEnd){
              return NULL;
          }
          int data = preorder[preIndex++];
          Node* node = new Node(data);
           int pos = findPos(inorder,inStart,inEnd,data);
        //   int pos = mp[data];       
          node->left = solve(preorder,inorder,preIndex, inStart, pos-1);
          node->right = solve(preorder,inorder,preIndex, pos+1,inEnd);
          
          return node;
          
      }
     
    Node* buildTree(int inorder[],int preorder[], int N)
    {
         n=N;
        //  for(int x=0;x<n;x++){
        //     mp[inorder[x]]=x;
        // }
        // since multiple Values are there that's why Simple map cant be used;
          
        int preIndex=0;
     return solve(preorder,inorder,preIndex,0,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends