//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends




//Function to return a tree created from postorder and inoreder traversals.
    
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
    
      Node* solve(int postorder[], int inorder[],int &postIndex,int inStart,int inEnd){
          if(postIndex < 0 || inStart>inEnd){
              return NULL;
          }
          int data = postorder[postIndex--];
          Node* node = new Node(data);
           int pos = findPos(inorder,inStart,inEnd,data);
        //   int pos = mp[data];       
          node->right = solve(postorder,inorder,postIndex, pos+1,inEnd);
          node->left = solve(postorder,inorder,postIndex, inStart, pos-1);
          
          return node;
          
      }

//Function to return a tree created from postorder and inoreder traversals.
 Node* buildTree(int inorder[], int postorder[], int N) {
    // Your code here
    n=N;
        //  for(int x=0;x<n;x++){
        //     mp[inorder[x]]=x;
        // }
        // since multiple Values are there that's why Simple map cant be used;
          
        int postIndex=n-1;
     return solve(postorder,inorder,postIndex,0,n-1);
    }
